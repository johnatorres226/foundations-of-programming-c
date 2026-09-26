/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Reference solution for exercises/01_object_macro.c
 * One approach among many — see PRD.md §10.
 */
#define CRATE_SIDE 4

int crate_volume(void) {
    return CRATE_SIDE * CRATE_SIDE * CRATE_SIDE;
}
