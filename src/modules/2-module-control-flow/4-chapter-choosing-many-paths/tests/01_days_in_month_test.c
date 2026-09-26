/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Tests days_in_month(): a switch over the month number, grouping months
 * that share a day count under one set of case labels.
 */
#include <assert.h>

int days_in_month(int month, int is_leap_year);

int main(void) {
    assert(days_in_month(1, 0) == 31);  /* January */
    assert(days_in_month(4, 0) == 30);  /* April */
    assert(days_in_month(12, 0) == 31); /* December */
    assert(days_in_month(2, 0) == 28);  /* February, common year */
    assert(days_in_month(2, 1) == 29);  /* February, leap year */
    assert(days_in_month(13, 0) == 0);  /* no such month */
    assert(days_in_month(0, 0) == 0);   /* no such month */
    return 0;
}
