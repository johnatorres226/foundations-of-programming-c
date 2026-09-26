/* Module 1, Chapter 4 — Getting Input and Showing Output
 * Reference solution for exercises/04_name_and_age.c.
 * One approach among many — see PRD.md §10.
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    int age = 0;
    char name[64];

    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Could not read a whole number for age.\n");
        return 1;
    }

    /* scanf("%d", ...) leaves the newline after the number sitting in the
     * input. Left alone, fgets() below would read that leftover newline
     * as an empty line instead of the name. Throw away characters up to
     * and including it before reading the real line. */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }

    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Could not read a name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0'; /* drop fgets()'s trailing newline */

    printf("%s is %d years old.\n", name, age);
    return 0;
}
