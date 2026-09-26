/* Module 2, Chapter 2.3 — Repeating Work
 * Reference solution for exercises/01_sum_of_digits.c
 * One approach among many — see PRD.md §10.
 */
int sum_of_digits(int n) {
    int total = 0;
    while (n > 0) {
        total += n % 10;
        n /= 10;
    }
    return total;
}
