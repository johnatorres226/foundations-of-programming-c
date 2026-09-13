/* Harness self-test fixture. Not part of the course. An unfinished stub,
 * on purpose - this is what an untouched learner exercise looks like: it
 * compiles clean under -Werror, then fails with a message instead of
 * guessing. Proves `make check-mine` fails on real, not-yet-done work. */
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    (void) a;
    (void) b;
    fprintf(stderr, "TODO: implement add() in exercises/01_add.c\n");
    exit(1);
}
