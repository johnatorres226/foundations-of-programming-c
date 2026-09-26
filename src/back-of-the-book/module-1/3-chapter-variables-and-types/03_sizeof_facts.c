/* Module 1, Chapter 1.3 — Variables and Types
 * Reference solution for exercises/03_sizeof_facts.c
 * One approach among many — see PRD.md §10.
 */
int size_of_char(void) {
    return (int) sizeof(char);
}

int int_is_at_least_two_bytes(void) {
    return sizeof(int) >= 2u;
}

int double_is_at_least_as_wide_as_float(void) {
    return sizeof(double) >= sizeof(float);
}
