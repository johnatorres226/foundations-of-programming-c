/* Module 1, Chapter 1.5 — When Things Break
 * Reference solution: sum the numbers 1 through 5 with a loop.
 * One approach among many — see ANSWERS.md.
 */
#include <stdio.h>

int main(void) {
    int total = 0;
    for (int i = 1; i <= 5; i++) {
        total += i;
    }
    printf("Sum: %d\n", total);
    return 0;
}
