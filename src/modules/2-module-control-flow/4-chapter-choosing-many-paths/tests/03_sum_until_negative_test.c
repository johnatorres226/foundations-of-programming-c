/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Tests sum_until_negative(): a loop that breaks the instant it sees a
 * negative number, never adding it or anything after it.
 */
#include <assert.h>

int sum_until_negative(const int *values, int n);

int main(void) {
    int a[] = {1, 2, 3, -1, 100};
    int b[] = {5, 5, 5};
    int c[] = {-9, 1, 1};
    int d[] = {0, 0, 0};

    assert(sum_until_negative(a, 5) == 6);  /* stops before -1 and 100 */
    assert(sum_until_negative(b, 3) == 15); /* no negative at all */
    assert(sum_until_negative(c, 3) == 0);  /* negative right away */
    assert(sum_until_negative(d, 3) == 0);  /* zero is not negative */
    return 0;
}
