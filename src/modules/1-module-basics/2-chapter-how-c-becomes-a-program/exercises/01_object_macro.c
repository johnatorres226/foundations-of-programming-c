/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Exercise: name a constant with #define, then use it in a function.
 *
 * Define a macro named CRATE_SIDE with the value 4, then implement
 * crate_volume() so it returns the volume of a cube-shaped crate with that
 * side length: CRATE_SIDE * CRATE_SIDE * CRATE_SIDE (should come out to 64).
 *
 * Check your work with:
 *   make check-mine CHAPTER=1-module-basics/2-chapter-how-c-becomes-a-program
 */
#include <stdio.h>
#include <stdlib.h>

int crate_volume(void) {
    fprintf(stderr, "TODO: define CRATE_SIDE and implement crate_volume() in "
                    "exercises/01_object_macro.c\n");
    exit(1);
}
