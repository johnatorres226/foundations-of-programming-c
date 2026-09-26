/* Module 2, Chapter 2.3 — Repeating Work
 * Tests count_multiples(): the classic off-by-one boundary. limit itself
 * is one of the multiples counted when it lands exactly on step, so the
 * loop condition must accept it, not stop one short. See CONTENT.html's
 * "Off-by-one: getting the boundary right" section.
 */
#include <assert.h>

int count_multiples(int limit, int step);

int main(void) {
    assert(count_multiples(10, 3) == 3);  /* 3, 6, 9 */
    assert(count_multiples(9, 3) == 3);   /* 3, 6, 9 — 9 must count */
    assert(count_multiples(10, 10) == 1); /* 10 only */
    assert(count_multiples(5, 10) == 0);  /* step bigger than limit */
    assert(count_multiples(1, 1) == 1);   /* 1 only */
    return 0;
}
