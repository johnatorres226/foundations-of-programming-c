/* Module 2, Chapter 2.1 — Making Decisions
 * Tests is_truthy(): 1 if C's own if would treat n as true, 0 if it would
 * treat n as false. Proves the learner can explain zero is false and
 * everything else — including negative numbers — is true.
 */
#include <assert.h>

int is_truthy(int n);

int main(void) {
    assert(is_truthy(0) == 0);
    assert(is_truthy(1) == 1);
    assert(is_truthy(-1) == 1);
    assert(is_truthy(42) == 1);
    assert(is_truthy(-100) == 1);
    return 0;
}
