/* Module 2, Chapter 2.1 — Making Decisions
 * Tests max_of_three(): the largest of three ints, using nested if/else
 * (no &&/|| yet — that is chapter 2.2).
 */
#include <assert.h>

int max_of_three(int a, int b, int c);

int main(void) {
    assert(max_of_three(1, 2, 3) == 3);
    assert(max_of_three(3, 2, 1) == 3);
    assert(max_of_three(2, 3, 1) == 3);
    assert(max_of_three(5, 5, 5) == 5);
    assert(max_of_three(-1, -2, -3) == -1);
    return 0;
}
