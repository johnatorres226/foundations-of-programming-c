/* Module 2, Chapter 2.3 — Repeating Work
 * Reference solution for exercises/04_count_multiples.c
 * One approach among many — see PRD.md §10.
 */
int count_multiples(int limit, int step) {
    int count = 0;
    for (int i = step; i <= limit; i += step) {
        count++;
    }
    return count;
}
