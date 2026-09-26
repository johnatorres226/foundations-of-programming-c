/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Exercise: use a switch with deliberate fall-through so a higher level
 * also collects every lower level's reward.
 *
 * Check your work with:
 *   make check-mine CHAPTER=2-module-control-flow/4-chapter-choosing-many-paths
 */
#include <stdio.h>
#include <stdlib.h>

int bonus_points(int level) {
    (void) level;
    fprintf(stderr, "TODO: implement bonus_points() in exercises/02_bonus_points.c\n");
    exit(1);
}
