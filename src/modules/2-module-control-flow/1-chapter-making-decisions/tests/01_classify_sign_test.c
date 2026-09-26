/* Module 2, Chapter 2.1 — Making Decisions
 * Tests classify_sign(): -1 for a negative number, 0 for zero, 1 for a
 * positive number. Proves an if/else if/else chain with three branches.
 */
#include <assert.h>

int classify_sign(int n);

int main(void) {
    assert(classify_sign(-5) == -1);
    assert(classify_sign(-1) == -1);
    assert(classify_sign(0) == 0);
    assert(classify_sign(1) == 1);
    assert(classify_sign(100) == 1);
    return 0;
}
