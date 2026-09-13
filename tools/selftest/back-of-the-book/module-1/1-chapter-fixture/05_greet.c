/* Harness self-test fixture. Not part of the course. Proves the program-
 * exercise shape: a full program whose stdout is diffed against
 * tests/05_greet.expected, with tests/05_greet.input piped to stdin. */
#include <stdio.h>

int main(void) {
    char name[64];
    if (scanf("%63s", name) != 1) {
        return 1;
    }
    printf("Hello, %s!\n", name);
    return 0;
}
