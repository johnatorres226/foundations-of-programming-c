/* Module 2, Chapter 2.3 — Repeating Work
 * Tests sum_of_digits(): a while loop that stops on its own once n reaches
 * zero. n = 0 must sum to 0 with the loop body never running — see
 * CONTENT.html's "The while loop" section.
 */
#include <assert.h>

int sum_of_digits(int n);

int main(void) {
    assert(sum_of_digits(0) == 0);
    assert(sum_of_digits(7) == 7);
    assert(sum_of_digits(123) == 6);
    assert(sum_of_digits(9999) == 36);
    assert(sum_of_digits(1001) == 2);
    return 0;
}
