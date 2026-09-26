/* Module 1, Chapter 4 — Getting Input and Showing Output
 * Reference solution for exercises/01_format_price.c.
 * One approach among many — see PRD.md §10.
 */
#include <stdio.h>

void format_price(char out[32], int cents) {
    int dollars = cents / 100;
    int remainder = cents % 100;
    snprintf(out, 32, "$%d.%02d", dollars, remainder);
}
