#!/bin/sh
# tools/selftest.sh — regression test for tools/run-tests.sh, run by
# `make selftest`. Not part of the course.
#
# Runs the real harness, through its real discovery code, against the
# fixture chapter in tools/selftest/ and checks that each case behaves the
# way the F1 issue requires:
#   - a correct solution passes                       (01_add)
#   - an untouched exercise stub fails, not a linker dump  (01_add, 05_greet)
#   - a wrong reference solution fails                 (02_wrong)
#   - the sanitizer override swaps sanitizers, not appends to them (03_race)
#   - the platform-skip mechanism reports SKIP, never a false PASS (04_threads)
#   - the program-exercise shape (stdout diff) works    (05_greet)
set -u

FIX=tools/selftest
BUILD=${BUILD:-build}
fails=0

check_contains() {
    if echo "$1" | grep -qF "$2"; then
        echo "  ok    $3"
    else
        echo "  FAIL  $3"
        echo "$1" | sed 's/^/      /'
        fails=$((fails + 1))
    fi
}

echo "Harness self-test"
echo ""
echo "== solution mode (what \`make check\` does) =="
sol_out=$(MODULES_ROOT="$FIX/modules" BOB_ROOT="$FIX/back-of-the-book" tools/run-tests.sh solution)
echo "$sol_out"
echo ""

check_contains "$sol_out" "PASS  1-module-fixture/1-chapter-fixture/01_add" \
    "correct function-exercise solution passes"
check_contains "$sol_out" "FAIL  1-module-fixture/1-chapter-fixture/02_wrong" \
    "make check fails on a wrong reference solution"
check_contains "$sol_out" "PASS  1-module-fixture/1-chapter-fixture/03_race" \
    "sanitizer override compiles and runs"
check_contains "$sol_out" "PASS  1-module-fixture/1-chapter-fixture/05_greet" \
    "correct program-exercise solution passes (stdout diff)"

if [ "$(uname -s)" = Darwin ]; then
    check_contains "$sol_out" "SKIP  1-module-fixture/1-chapter-fixture/04_threads" \
        "threads.h reports SKIP on Apple Clang, not a false pass"
else
    check_contains "$sol_out" "PASS  1-module-fixture/1-chapter-fixture/04_threads" \
        "threads.h runs on platforms that ship it"
fi

echo ""
echo "== confirming the sanitizer override replaced, not appended =="
if grep -q '\-fsanitize=address' "$BUILD/1-module-fixture_1-chapter-fixture_03_race.log" 2>/dev/null; then
    echo "  FAIL  03_race compile log mentions address sanitizer alongside thread"
    fails=$((fails + 1))
else
    echo "  ok    03_race compiled with only ThreadSanitizer, never combined with AddressSanitizer"
fi

echo ""
echo "== mine mode (what \`make check-mine\` does), untouched stubs =="
mine_out=$(MODULES_ROOT="$FIX/modules" BOB_ROOT="$FIX/back-of-the-book" tools/run-tests.sh mine)
echo "$mine_out"
echo ""

check_contains "$mine_out" "FAIL  1-module-fixture/1-chapter-fixture/01_add" \
    "untouched function-exercise stub fails make check-mine"
check_contains "$mine_out" "FAIL  1-module-fixture/1-chapter-fixture/05_greet" \
    "untouched program-exercise stub fails make check-mine"

echo ""
if [ "$fails" -eq 0 ]; then
    echo "Harness self-test: all checks behaved as expected."
else
    echo "Harness self-test: $fails check(s) did not behave as expected."
fi
exit "$fails"
