/* Module 2, Chapter 2.2 — Combining Conditions
 * Reference solution for exercises/02_is_valid_login.c
 * One approach among many — see PRD.md §10.
 */
int is_valid_login(int has_correct_password, int is_banned) {
    return has_correct_password && !is_banned;
}
