#!/bin/sh
# tools/run-tests.sh — the TDD harness. See .claude/PRD.md §9 and §11.
#
# Usage:
#   tools/run-tests.sh solution [CHAPTER]   # backs `make check`
#   tools/run-tests.sh mine     [CHAPTER]   # backs `make check-mine`
#
# Walks every tests/ directory under MODULES_ROOT (default src/modules) and,
# for each exercise it finds, compiles either the reference solution
# (BOB_ROOT, default src/back-of-the-book) or the learner's own exercises/
# file against that exercise's tests/. Reports PASS, FAIL, or SKIP per
# exercise. CHAPTER, if given, is a substring filter on the module/chapter
# path so one chapter can be checked instead of the whole course.
#
# Two exercise shapes, told apart by what's in tests/:
#   function exercise — tests/NN_name_test.c has main()+assert(); it is
#     compiled together with the exercise/solution file (which has no main)
#     and the combined program must exit 0.
#   program exercise  — tests/NN_name.expected holds the exact stdout a
#     full program (with its own main) must produce. tests/NN_name.input,
#     if present, is piped in as stdin.
#
# Two per-exercise overrides, read from files next to the test:
#   tests/NN_name.sanitize   — "thread" swaps in ThreadSanitizer instead of
#     the course default (AddressSanitizer + UBSan cannot combine with it).
#   tests/NN_name.requires   — a header name (e.g. "threads.h") that must
#     compile on this platform or the exercise is reported SKIP, never a
#     false PASS or FAIL. Apple Clang lacks <threads.h>, for example.

MODE=$1
CHAPTER=${2:-}

CC=${CC:-cc}
CSTD=${CSTD:--std=c17}
WARN=${WARN:--Wall -Wextra -Werror}
DEBUG=${DEBUG:--g}
DEFAULT_SAN=${SAN:--fsanitize=address,undefined}
BUILD=${BUILD:-build}
MODULES_ROOT=${MODULES_ROOT:-src/modules}
BOB_ROOT=${BOB_ROOT:-src/back-of-the-book}

mkdir -p "$BUILD"

pass=0
fail=0
skip=0
found=0

# probe_header HEADER — true if a trivial translation unit including
# <HEADER> compiles here. Used for the platform-skip mechanism.
probe_header() {
    printf '#include <%s>\nint main(void) { return 0; }\n' "$1" \
        >"$BUILD/.probe.c"
    "$CC" $CSTD "$BUILD/.probe.c" -o "$BUILD/.probe" 2>/dev/null
    rc=$?
    rm -f "$BUILD/.probe.c" "$BUILD/.probe"
    return $rc
}

# sanitize_flags TESTS_DIR BASE — echoes the -fsanitize flag to build with.
sanitize_flags() {
    override="$1/$2.sanitize"
    if [ -f "$override" ]; then
        case "$(cat "$override")" in
            thread) echo "-fsanitize=thread" ;;
            none) echo "" ;;
            *) echo "$DEFAULT_SAN" ;;
        esac
    else
        echo "$DEFAULT_SAN"
    fi
}

# run_function_exercise SRC TEST_C SAN LABEL — compiles SRC (no main) with
# TEST_C (main + asserts) and runs the result. PASS if it exits 0.
run_function_exercise() {
    src=$1; test_c=$2; san=$3; label=$4
    out="$BUILD/$(echo "$label" | tr '/.' '__')"
    if ! "$CC" $CSTD $WARN $DEBUG $san -pthread "$src" "$test_c" -o "$out" 2>"$out.log"; then
        echo "  FAIL  $label (compile error)"
        sed 's/^/      /' "$out.log"
        return 1
    fi
    if "$out" >"$out.stdout" 2>"$out.stderr"; then
        echo "  PASS  $label"
        return 0
    fi
    echo "  FAIL  $label (a check did not pass — see below)"
    sed 's/^/      /' "$out.stderr"
    return 1
}

# run_program_exercise SRC EXPECTED INPUT SAN LABEL — compiles SRC (has its
# own main) and diffs its stdout against EXPECTED, feeding INPUT (if any)
# to stdin.
run_program_exercise() {
    src=$1; expected=$2; input=$3; san=$4; label=$5
    out="$BUILD/$(echo "$label" | tr '/.' '__')"
    if ! "$CC" $CSTD $WARN $DEBUG $san -pthread "$src" -o "$out" 2>"$out.log"; then
        echo "  FAIL  $label (compile error)"
        sed 's/^/      /' "$out.log"
        return 1
    fi
    if [ -n "$input" ]; then
        "$out" <"$input" >"$out.stdout" 2>"$out.stderr"
    else
        "$out" </dev/null >"$out.stdout" 2>"$out.stderr"
    fi
    rc=$?
    if [ "$rc" -ne 0 ]; then
        echo "  FAIL  $label (exited $rc instead of printing its answer)"
        sed 's/^/      /' "$out.stderr"
        return 1
    fi
    if diff -u "$expected" "$out.stdout" >"$out.diff" 2>&1; then
        echo "  PASS  $label"
        return 0
    fi
    echo "  FAIL  $label (output did not match $expected)"
    sed 's/^/      /' "$out.diff"
    return 1
}

for tests_dir in $(find "$MODULES_ROOT" -type d -name tests 2>/dev/null | sort); do
    chapter_dir=$(dirname "$tests_dir")
    rel=${chapter_dir#"$MODULES_ROOT"/}
    module_seg=${rel%%/*}
    chapter_seg=${rel#*/}
    module_num=${module_seg%%-*}
    bob_dir="$BOB_ROOT/module-$module_num/$chapter_seg"
    exercises_dir="$chapter_dir/exercises"

    if [ -n "$CHAPTER" ]; then
        case "$module_seg/$chapter_seg" in
            *"$CHAPTER"*) : ;;
            *) continue ;;
        esac
    fi

    for test_c in "$tests_dir"/*_test.c; do
        [ -e "$test_c" ] || continue
        base=$(basename "$test_c" _test.c)
        label="$module_seg/$chapter_seg/$base"
        found=$((found + 1))

        requires="$tests_dir/$base.requires"
        if [ -f "$requires" ] && ! probe_header "$(cat "$requires")"; then
            echo "  SKIP  $label (needs <$(cat "$requires")>, not available with $CC on this platform)"
            skip=$((skip + 1))
            continue
        fi

        if [ "$MODE" = solution ]; then
            src_c="$bob_dir/$base.c"
            missing_msg="reference solution not written yet: $src_c (PRD §9 — write it before this chapter ships)"
        else
            src_c="$exercises_dir/$base.c"
            missing_msg="exercise file not found: $src_c"
        fi
        if [ ! -f "$src_c" ]; then
            echo "  FAIL  $label ($missing_msg)"
            fail=$((fail + 1))
            continue
        fi

        san=$(sanitize_flags "$tests_dir" "$base")
        if run_function_exercise "$src_c" "$test_c" "$san" "$label"; then
            pass=$((pass + 1))
        else
            fail=$((fail + 1))
        fi
    done

    for expected in "$tests_dir"/*.expected; do
        [ -e "$expected" ] || continue
        base=$(basename "$expected" .expected)
        label="$module_seg/$chapter_seg/$base"
        found=$((found + 1))

        requires="$tests_dir/$base.requires"
        if [ -f "$requires" ] && ! probe_header "$(cat "$requires")"; then
            echo "  SKIP  $label (needs <$(cat "$requires")>, not available with $CC on this platform)"
            skip=$((skip + 1))
            continue
        fi

        if [ "$MODE" = solution ]; then
            src_c="$bob_dir/$base.c"
            missing_msg="reference solution not written yet: $src_c (PRD §9 — write it before this chapter ships)"
        else
            src_c="$exercises_dir/$base.c"
            missing_msg="exercise file not found: $src_c"
        fi
        if [ ! -f "$src_c" ]; then
            echo "  FAIL  $label ($missing_msg)"
            fail=$((fail + 1))
            continue
        fi

        input=""
        [ -f "$tests_dir/$base.input" ] && input="$tests_dir/$base.input"

        san=$(sanitize_flags "$tests_dir" "$base")
        if run_program_exercise "$src_c" "$expected" "$input" "$san" "$label"; then
            pass=$((pass + 1))
        else
            fail=$((fail + 1))
        fi
    done
done

echo ""
if [ "$found" -eq 0 ]; then
    if [ -n "$CHAPTER" ]; then
        echo "No exercises found under CHAPTER=$CHAPTER — nothing to check."
    else
        echo "No tests found yet under $MODULES_ROOT — nothing to check."
    fi
    exit 0
fi
echo "  $pass passed, $fail failed, $skip skipped"
[ "$fail" -eq 0 ]
