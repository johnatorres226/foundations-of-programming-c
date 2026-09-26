/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Exercise: write a function-like macro, then prove it needs full
 * parentheses.
 *
 * Define SQUARE(x) so it expands to ((x) * (x)) — not the tempting-looking
 * x * x. Then implement:
 *   square_of_seven() -> SQUARE(7)      should come out to 49
 *   square_of_sum()   -> SQUARE(3 + 4)  should also come out to 49
 *
 * If SQUARE is missing its parentheses, square_of_seven() still passes —
 * but square_of_sum() computes the wrong number, because the preprocessor
 * pasted in the raw text "3 + 4" wherever x appeared. See CONTENT.html's
 * "Preprocess" section for why.
 *
 * Check your work with:
 *   make check-mine CHAPTER=1-module-basics/2-chapter-how-c-becomes-a-program
 */
#include <stdio.h>
#include <stdlib.h>

int square_of_seven(void) {
    fprintf(stderr, "TODO: define SQUARE(x) and implement square_of_seven() in "
                    "exercises/02_function_macro.c\n");
    exit(1);
}

int square_of_sum(void) {
    fprintf(stderr, "TODO: define SQUARE(x) and implement square_of_sum() in "
                    "exercises/02_function_macro.c\n");
    exit(1);
}
