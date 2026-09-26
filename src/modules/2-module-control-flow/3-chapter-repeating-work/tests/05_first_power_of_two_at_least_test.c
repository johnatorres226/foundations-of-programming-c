/* Module 2, Chapter 2.3 — Repeating Work
 * Tests first_power_of_two_at_least(): a while loop whose termination is
 * provable — n doubles every pass, so it always reaches target eventually.
 * target = 8 checks the loop stops exactly there instead of overshooting
 * to 16. See CONTENT.html's "Loops that don't stop" section.
 */
#include <assert.h>

int first_power_of_two_at_least(int target);

int main(void) {
    assert(first_power_of_two_at_least(0) == 1);
    assert(first_power_of_two_at_least(1) == 1);
    assert(first_power_of_two_at_least(5) == 8);
    assert(first_power_of_two_at_least(8) == 8);
    assert(first_power_of_two_at_least(1000) == 1024);
    return 0;
}
