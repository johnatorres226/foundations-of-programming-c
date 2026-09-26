/* Module 2, Chapter 2.3 — Repeating Work
 * Tests count_digits(): a do/while loop that must run its body at least
 * once. count_digits(0) has to come out as 1, not 0 — a plain while loop
 * would skip the body entirely and get this wrong. See CONTENT.html's
 * "The do/while loop" section.
 */
#include <assert.h>

int count_digits(int n);

int main(void) {
    assert(count_digits(0) == 1);
    assert(count_digits(9) == 1);
    assert(count_digits(10) == 2);
    assert(count_digits(999) == 3);
    assert(count_digits(1000) == 4);
    return 0;
}
