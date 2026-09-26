/* Module 2, Chapter 2.2 — Combining Conditions
 * Reference solution for exercises/03_should_sound_alarm.c
 * One approach among many — see PRD.md §10.
 */
int should_sound_alarm(int smoke_detected, int door_forced_open) {
    return smoke_detected || door_forced_open;
}
