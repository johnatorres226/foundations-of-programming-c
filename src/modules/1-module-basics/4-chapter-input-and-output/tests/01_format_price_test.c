/* Module 1, Chapter 4 — Getting Input and Showing Output
 * tests/01_format_price_test.c — assert-based test. Written before the
 * solution, per PRD.md §9. Compiled together with either the reference
 * solution or the learner's exercises/01_format_price.c.
 */
#include <assert.h>
#include <string.h>

void format_price(char out[32], int cents);

int main(void) {
    char out[32];

    format_price(out, 305);
    assert(strcmp(out, "$3.05") == 0);

    format_price(out, 5);
    assert(strcmp(out, "$0.05") == 0);

    format_price(out, 1000);
    assert(strcmp(out, "$10.00") == 0);

    format_price(out, 0);
    assert(strcmp(out, "$0.00") == 0);

    return 0;
}
