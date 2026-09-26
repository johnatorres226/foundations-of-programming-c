/* Module 2, Chapter 2.2 — Combining Conditions
 * Tests in_range(): true only when value sits between low and high,
 * inclusive on both ends. Written first, per PRD.md §9 — it fails against
 * the stub until exercises/01_in_range.c is implemented.
 */
#include <assert.h>

int in_range(int value, int low, int high);

int main(void) {
    /* Inside the range. */
    assert(in_range(5, 1, 10) == 1);

    /* Exactly on each boundary — both ends count as "in range". */
    assert(in_range(1, 1, 10) == 1);
    assert(in_range(10, 1, 10) == 1);

    /* Outside the range, on each side. */
    assert(in_range(0, 1, 10) == 0);
    assert(in_range(11, 1, 10) == 0);

    /* A negative range works the same way. */
    assert(in_range(-5, -10, -1) == 1);
    assert(in_range(-11, -10, -1) == 0);

    /* && always produces exactly 0 or 1, never the operand's own value —
     * check that even a "wide" true range still returns 1, not something
     * else. */
    assert(in_range(500, 0, 1000) == 1);

    return 0;
}
