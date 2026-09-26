/* Module 1, Chapter 4 — Getting Input and Showing Output
 * tests/02_format_row_test.c — assert-based test. Written before the
 * solution, per PRD.md §9. Compiled together with either the reference
 * solution or the learner's exercises/02_format_row.c.
 */
#include <assert.h>
#include <string.h>

void format_row(char out[64], char name[], int score);

int main(void) {
    char out[64];

    format_row(out, "Ann", 87);
    assert(strcmp(out, "Ann          87\n") == 0);

    /* Name exactly fills the 10-char field: no extra padding is added. */
    format_row(out, "Alexandria", 6);
    assert(strcmp(out, "Alexandria    6\n") == 0);

    format_row(out, "Bo", 140);
    assert(strcmp(out, "Bo          140\n") == 0);

    /* Name is longer than the 10-char field: width is a minimum, not a
     * cap, so nothing gets cut off. */
    format_row(out, "Constantinople", 5);
    assert(strcmp(out, "Constantinople    5\n") == 0);

    return 0;
}
