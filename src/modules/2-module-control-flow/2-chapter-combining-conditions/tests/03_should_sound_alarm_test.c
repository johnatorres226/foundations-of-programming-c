/* Module 2, Chapter 2.2 — Combining Conditions
 * Tests should_sound_alarm(): the alarm sounds if EITHER sensor trips.
 * Proves ||.
 */
#include <assert.h>

int should_sound_alarm(int smoke_detected, int door_forced_open);

int main(void) {
    /* Neither sensor tripped: quiet. */
    assert(should_sound_alarm(0, 0) == 0);

    /* Either sensor alone is enough to sound the alarm. */
    assert(should_sound_alarm(1, 0) == 1);
    assert(should_sound_alarm(0, 1) == 1);

    /* Both at once: still just "sound the alarm", not double. */
    assert(should_sound_alarm(1, 1) == 1);

    /* Any nonzero reading counts as "tripped" (Chapter 2.1), and || still
     * collapses the result to exactly 0 or 1. */
    assert(should_sound_alarm(9, 0) == 1);

    return 0;
}
