/* Module 2, Chapter 2.3 — Repeating Work
 * Tests sum_range(): a for loop over a known, bounded count of numbers.
 * sum_range(5, 5) checks the loop runs exactly once, not zero or two times
 * — see CONTENT.html's "The for loop" section.
 */
#include <assert.h>

int sum_range(int lo, int hi);

int main(void) {
    assert(sum_range(1, 5) == 15);
    assert(sum_range(5, 5) == 5);
    assert(sum_range(-3, 3) == 0);
    assert(sum_range(10, 12) == 33);
    return 0;
}
