/* Module 2, Chapter 2.3 — Repeating Work
 * Reference solution for exercises/05_first_power_of_two_at_least.c
 * One approach among many — see PRD.md §10.
 */
int first_power_of_two_at_least(int target) {
    int n = 1;
    while (n < target) {
        n *= 2;
    }
    return n;
}
