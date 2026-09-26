/* Module 2, Chapter 2.3 — Repeating Work
 * Reference solution for exercises/02_count_digits.c
 * One approach among many — see PRD.md §10.
 */
int count_digits(int n) {
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n > 0);
    return count;
}
