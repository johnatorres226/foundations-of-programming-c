/* Module 1, Chapter 1.3 — Variables and Types
 * Tests wrap_add(): unsigned char addition that wraps around instead of
 * growing past its fixed size. See CONTENT.html's "Why fixed sizes matter".
 */
#include <assert.h>

unsigned char wrap_add(unsigned char a, unsigned char b);

int main(void) {
    assert(wrap_add(0, 0) == 0);
    assert(wrap_add(10, 20) == 30);
    assert(wrap_add(255, 1) == 0);
    assert(wrap_add(200, 100) == 44);
    return 0;
}
