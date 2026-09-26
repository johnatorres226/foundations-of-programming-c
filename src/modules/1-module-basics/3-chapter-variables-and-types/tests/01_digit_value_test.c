/* Module 1, Chapter 1.3 — Variables and Types
 * Tests digit_value(): a char digit ('0'-'9') converted to the int it means.
 */
#include <assert.h>

int digit_value(char c);

int main(void) {
    assert(digit_value('0') == 0);
    assert(digit_value('3') == 3);
    assert(digit_value('5') == 5);
    assert(digit_value('9') == 9);
    return 0;
}
