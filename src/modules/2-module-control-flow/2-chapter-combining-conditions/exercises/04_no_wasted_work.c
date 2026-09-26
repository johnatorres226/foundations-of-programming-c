/* Module 2, Chapter 2.2 — Combining Conditions
 * Exercise: prove that short-circuit evaluation is real, not just a rule
 * in a textbook.
 *
 * expensive_check() below stands in for any slow or unsafe piece of work —
 * a network call, a big search, an action that is only safe once a guard
 * has been checked. It counts every time it actually runs, in
 * expensive_check_count, so the test can prove whether it ran at all. You
 * do not need to change expensive_check() or its counter — write
 * safe_to_proceed() so that a false guard_ok skips expensive_check()
 * entirely.
 *
 * Check your work with:
 *   make check-mine CHAPTER=2-module-control-flow/2-chapter-combining-conditions
 */
#include <stdio.h>
#include <stdlib.h>

int expensive_check_count = 0;

int expensive_check(int value) {
    expensive_check_count++;
    return value > 0;
}

int safe_to_proceed(int guard_ok, int value) {
    (void) guard_ok;
    (void) value;
    fprintf(stderr, "TODO: implement safe_to_proceed() in "
                    "exercises/04_no_wasted_work.c\n");
    exit(1);
}
