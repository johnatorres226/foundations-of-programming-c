/* Harness self-test fixture. Not part of the course. Deliberately WRONG
 * on purpose, so `make selftest` can prove `make check` fails on a bad
 * reference solution. Do not "fix" this file. */
int subtract(int a, int b) {
    return a + b; /* wrong: should be a - b */
}
