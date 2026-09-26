/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Tests count_letters(): a loop that uses continue to skip non-letters
 * and break to stop entirely at a '#' marker.
 */
#include <assert.h>

int count_letters(const char *s);

int main(void) {
    assert(count_letters("abc 123") == 3);       /* digits and space skipped */
    assert(count_letters("ab#cd") == 2);          /* stops at '#', "cd" unseen */
    assert(count_letters("Hello, World!") == 10); /* punctuation skipped */
    assert(count_letters("###") == 0);            /* stops before any letter */
    assert(count_letters("") == 0);                /* empty string */
    return 0;
}
