/* Module 2, Chapter 2.2 — Combining Conditions
 * Reference solution for exercises/04_no_wasted_work.c
 * One approach among many — see PRD.md §10.
 *
 * expensive_check() and its counter are provided scaffolding (see the
 * exercise stub) — the only line that changes is safe_to_proceed() itself.
 */
int expensive_check_count = 0;

int expensive_check(int value) {
    expensive_check_count++;
    return value > 0;
}

int safe_to_proceed(int guard_ok, int value) {
    return guard_ok && expensive_check(value);
}
