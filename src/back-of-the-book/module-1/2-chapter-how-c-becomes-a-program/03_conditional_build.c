/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Reference solution for exercises/03_conditional_build.c
 * One approach among many — see PRD.md §10.
 */
#define METRIC_UNITS 1

#if METRIC_UNITS
int box_capacity(void) {
    return 100;
}
#else
int box_capacity(void) {
    return 12;
}
#endif
