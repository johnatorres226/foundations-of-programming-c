/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Reference solution for exercises/01_days_in_month.c
 * One approach among many — see PRD.md §10.
 */
int days_in_month(int month, int is_leap_year) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return is_leap_year ? 29 : 28;
    default:
        return 0;
    }
}
