/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Tests exercises/02_function_macro.c (or the reference solution).
 *
 * Proves: a function-like macro needs full parentheses around its
 * parameter, every place it appears, or it silently computes the wrong
 * answer for some inputs while still looking correct for others.
 * square_of_seven() would pass even with a broken SQUARE(x); square_of_sum()
 * only passes if SQUARE is written correctly.
 */
#include <assert.h>

int square_of_seven(void);
int square_of_sum(void);

int main(void) {
    assert(square_of_seven() == 49);
    assert(square_of_sum() == 49);
    return 0;
}
