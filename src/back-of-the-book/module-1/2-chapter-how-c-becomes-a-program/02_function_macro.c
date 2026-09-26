/* Module 1, Chapter 1.2 — How C Becomes a Program
 * Reference solution for exercises/02_function_macro.c
 * One approach among many — see PRD.md §10.
 */
#define SQUARE(x) ((x) * (x))

int square_of_seven(void) {
    return SQUARE(7);
}

int square_of_sum(void) {
    return SQUARE(3 + 4);
}
