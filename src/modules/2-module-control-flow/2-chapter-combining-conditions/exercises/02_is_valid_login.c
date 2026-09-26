/* Module 2, Chapter 2.2 — Combining Conditions
 * Exercise: a login is valid only when the password is correct AND the
 * account is NOT banned.
 *
 * Check your work with:
 *   make check-mine CHAPTER=2-module-control-flow/2-chapter-combining-conditions
 */
#include <stdio.h>
#include <stdlib.h>

int is_valid_login(int has_correct_password, int is_banned) {
    (void) has_correct_password;
    (void) is_banned;
    fprintf(stderr,
            "TODO: implement is_valid_login() in exercises/02_is_valid_login.c\n");
    exit(1);
}
