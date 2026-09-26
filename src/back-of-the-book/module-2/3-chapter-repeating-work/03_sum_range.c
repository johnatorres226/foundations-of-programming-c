/* Module 2, Chapter 2.3 — Repeating Work
 * Reference solution for exercises/03_sum_range.c
 * One approach among many — see PRD.md §10.
 */
int sum_range(int lo, int hi) {
    int total = 0;
    for (int i = lo; i <= hi; i++) {
        total += i;
    }
    return total;
}
