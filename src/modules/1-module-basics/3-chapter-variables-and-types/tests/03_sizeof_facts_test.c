/* Module 1, Chapter 1.3 — Variables and Types
 * Tests three predictions about sizeof. Each fact holds on every platform
 * this course targets — see CONTENT.html's "Asking sizeof" section for which
 * sizeof facts the C standard actually guarantees versus which just happen
 * to be true everywhere in practice.
 */
#include <assert.h>

int size_of_char(void);
int int_is_at_least_two_bytes(void);
int double_is_at_least_as_wide_as_float(void);

int main(void) {
    assert(size_of_char() == 1);
    assert(int_is_at_least_two_bytes() == 1);
    assert(double_is_at_least_as_wide_as_float() == 1);
    return 0;
}
