/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Exercise: use #if/#else/#endif to compile only one of two versions of a
 * function.
 *
 * METRIC_UNITS is already defined below as 1, which takes the #if branch.
 * Implement box_capacity() in that branch so it returns 100 (a metric
 * reading, in liters x100). Leave the #else branch exactly as it is — the
 * preprocessor deletes it before the compiler ever reads it, so it does not
 * need to be correct, or even valid C, to compile clean. Once your test
 * passes, try replacing its body with nonsense and recompiling, to see that
 * for yourself.
 *
 * Check your work with:
 *   make check-mine CHAPTER=1-module-basics/2-chapter-how-c-becomes-a-program
 */
#include <stdio.h>
#include <stdlib.h>

#define METRIC_UNITS 1

#if METRIC_UNITS
int box_capacity(void) {
    fprintf(stderr, "TODO: implement box_capacity() in "
                    "exercises/03_conditional_build.c\n");
    exit(1);
}
#else
int box_capacity(void) {
    return 12;
}
#endif
