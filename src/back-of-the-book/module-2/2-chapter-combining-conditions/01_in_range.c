/* Module 2, Chapter 2.2 — Combining Conditions
 * Reference solution for exercises/01_in_range.c
 * One approach among many — see PRD.md §10.
 */
int in_range(int value, int low, int high) {
    return value >= low && value <= high;
}
