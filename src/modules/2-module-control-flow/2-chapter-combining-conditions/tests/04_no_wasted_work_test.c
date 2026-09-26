/* Module 2, Chapter 2.2 — Combining Conditions
 * Tests safe_to_proceed(): proves short-circuit evaluation is real, not
 * just a rule in a textbook. expensive_check_count (defined in
 * exercises/04_no_wasted_work.c, alongside the provided expensive_check()
 * helper) only goes up when expensive_check() actually runs.
 */
#include <assert.h>

extern int expensive_check_count;
int safe_to_proceed(int guard_ok, int value);

int main(void) {
    /* guard_ok is false: && already knows the whole expression is false
     * without looking at the right side. expensive_check() must NOT run. */
    expensive_check_count = 0;
    assert(safe_to_proceed(0, 5) == 0);
    assert(expensive_check_count == 0);

    /* guard_ok is true: now && has to check the right side, so
     * expensive_check() must run exactly once. */
    expensive_check_count = 0;
    assert(safe_to_proceed(1, 5) == 1);
    assert(expensive_check_count == 1);

    expensive_check_count = 0;
    assert(safe_to_proceed(1, -5) == 0);
    assert(expensive_check_count == 1);

    /* A false guard skips the check every time, no matter what value is —
     * even a value that would itself pass the check. */
    expensive_check_count = 0;
    assert(safe_to_proceed(0, 999) == 0);
    assert(expensive_check_count == 0);

    return 0;
}
