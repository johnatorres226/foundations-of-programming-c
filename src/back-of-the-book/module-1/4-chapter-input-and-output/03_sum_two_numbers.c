/* Module 1, Chapter 4 — Getting Input and Showing Output
 * Reference solution for exercises/03_sum_two_numbers.c.
 * One approach among many — see PRD.md §10.
 */
#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;

    /* %d skips any leading whitespace on its own, including newlines, so
     * it does not matter whether the two numbers are on one line or two. */
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Could not read two whole numbers.\n");
        return 1;
    }

    printf("Sum: %d\n", a + b);
    return 0;
}
