/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Tests bonus_points(): a switch that deliberately falls through, so a
 * higher membership level also collects every lower level's reward.
 */
#include <assert.h>

int bonus_points(int level);

int main(void) {
    assert(bonus_points(1) == 10);  /* level 1 only */
    assert(bonus_points(2) == 60);  /* falls through into level 1's reward */
    assert(bonus_points(3) == 160); /* falls through into 2 and then 1 */
    assert(bonus_points(0) == 0);   /* not a real level */
    assert(bonus_points(5) == 0);   /* not a real level */
    return 0;
}
