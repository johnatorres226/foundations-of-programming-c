/* Module 2, Chapter 2.1 — Making Decisions
 * Tests grade_letter(): a score turned into a letter grade with an
 * if/else if/else chain. Boundaries (90, 80, 70, 60) are checked on
 * purpose — an off-by-one or a chain in the wrong order fails these.
 */
#include <assert.h>

char grade_letter(int score);

int main(void) {
    assert(grade_letter(95) == 'A');
    assert(grade_letter(90) == 'A');
    assert(grade_letter(89) == 'B');
    assert(grade_letter(80) == 'B');
    assert(grade_letter(79) == 'C');
    assert(grade_letter(70) == 'C');
    assert(grade_letter(65) == 'D');
    assert(grade_letter(60) == 'D');
    assert(grade_letter(59) == 'F');
    assert(grade_letter(0) == 'F');
    return 0;
}
