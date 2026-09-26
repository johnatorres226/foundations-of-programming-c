/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Reference solution for exercises/03_sum_until_negative.c
 * One approach among many — see PRD.md §10.
 */
int sum_until_negative(const int *values, int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (values[i] < 0) {
            break;
        }
        total += values[i];
    }

    return total;
}
