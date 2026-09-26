/* Module 2, Chapter 2.2 — Combining Conditions
 * Exercise: the alarm should sound if EITHER sensor has tripped.
 *
 * Check your work with:
 *   make check-mine CHAPTER=2-module-control-flow/2-chapter-combining-conditions
 */
#include <stdio.h>
#include <stdlib.h>

int should_sound_alarm(int smoke_detected, int door_forced_open) {
    (void) smoke_detected;
    (void) door_forced_open;
    fprintf(stderr, "TODO: implement should_sound_alarm() in "
                    "exercises/03_should_sound_alarm.c\n");
    exit(1);
}
