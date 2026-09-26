/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Tests exercises/01_object_macro.c (or the reference solution).
 *
 * Proves: an object-like macro (#define CRATE_SIDE 4) is swapped for its
 * literal value everywhere it appears, before the compiler ever sees the
 * name CRATE_SIDE. This test only calls the finished function — it has no
 * way to see the macro itself, because the preprocessor already erased it.
 */
#include <assert.h>

int crate_volume(void);

int main(void) {
    assert(crate_volume() == 64);
    return 0;
}
