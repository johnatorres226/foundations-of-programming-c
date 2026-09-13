/* Module 1, Chapter 1.1 — Your First Program, Line by Line
 * Exercise: print exactly one line, quotation marks included:
 *   The computer printed "Hello, World!" on the screen.
 *
 * A double quote inside a string literal needs a backslash in front of it
 * (\"), or the compiler thinks the string ends early. Check your work with:
 *   make check-mine CHAPTER=1-module-basics/1-chapter-first-program
 */
#include <stdio.h>

int main(void) {
    fprintf(stderr,
            "TODO: print the quoted message in exercises/03_quoted_message.c\n");
    return 1;
}
