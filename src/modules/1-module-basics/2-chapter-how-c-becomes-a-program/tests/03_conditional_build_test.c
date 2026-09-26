/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Tests exercises/03_conditional_build.c (or the reference solution).
 *
 * Proves: #if/#else/#endif chooses which block of text reaches the
 * compiler at all. Only one version of box_capacity() is ever compiled;
 * the other is deleted before the compiler runs.
 */
#include <assert.h>

int box_capacity(void);

int main(void) {
    assert(box_capacity() == 100);
    return 0;
}
