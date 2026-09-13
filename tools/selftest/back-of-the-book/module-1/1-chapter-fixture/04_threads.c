/* Harness self-test fixture. Not part of the course. Exercises the
 * platform-skip mechanism (see tests/04_threads.requires): <threads.h>
 * is optional C11 and absent on Apple Clang, so the harness must probe
 * for it and report SKIP, never a false PASS. */
int run(void *arg) {
    int *out = arg;
    *out = 42;
    return 0;
}
