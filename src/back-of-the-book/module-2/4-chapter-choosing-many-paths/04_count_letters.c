/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Reference solution for exercises/04_count_letters.c
 * One approach among many — see PRD.md §10.
 */
int count_letters(const char *s) {
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '#') {
            break;
        }
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            continue;
        }
        count++;
    }

    return count;
}
