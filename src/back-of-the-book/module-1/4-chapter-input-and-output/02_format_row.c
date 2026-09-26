/* Module 1, Chapter 4 — Getting Input and Showing Output
 * Reference solution for exercises/02_format_row.c.
 * One approach among many — see PRD.md §10.
 */
#include <stdio.h>

void format_row(char out[64], char name[], int score) {
    snprintf(out, 64, "%-10s%5d\n", name, score);
}
