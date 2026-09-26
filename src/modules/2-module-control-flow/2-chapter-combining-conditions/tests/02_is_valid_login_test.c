/* Module 2, Chapter 2.2 — Combining Conditions
 * Tests is_valid_login(): a login is only valid when the password is
 * correct AND the account is NOT banned. Proves && combined with !.
 */
#include <assert.h>

int is_valid_login(int has_correct_password, int is_banned);

int main(void) {
    /* Correct password, not banned: allowed in. */
    assert(is_valid_login(1, 0) == 1);

    /* Correct password, but banned: a banned account never gets in, even
     * with the right password. This is the safety case the chapter's
     * "why it matters" section is built on. */
    assert(is_valid_login(1, 1) == 0);

    /* Wrong password: never allowed in, banned or not. */
    assert(is_valid_login(0, 0) == 0);
    assert(is_valid_login(0, 1) == 0);

    /* C treats any nonzero value as true (Chapter 2.1) — a caller that
     * passes 5 instead of 1 for "yes" must still work, and the result must
     * still be exactly 0 or 1, never 5. */
    assert(is_valid_login(5, 0) == 1);
    assert(is_valid_login(5, 7) == 0);

    return 0;
}
