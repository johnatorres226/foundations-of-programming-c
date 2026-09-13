/* Harness self-test fixture. Not part of the course.
 * Proves the function-exercise shape: this file has main() and asserts;
 * add() comes from whichever side (solution or exercise) is under test. */
#include <assert.h>

int add(int a, int b);

int main(void) {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    return 0;
}
