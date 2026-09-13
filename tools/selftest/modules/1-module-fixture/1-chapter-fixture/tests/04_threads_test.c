/* Harness self-test fixture. Not part of the course. Only compiled where
 * <threads.h> exists - see tests/04_threads.requires. */
#include <assert.h>
#include <threads.h>

int run(void *arg);

int main(void) {
    thrd_t t;
    int result = 0;
    thrd_create(&t, run, &result);
    thrd_join(t, NULL);
    assert(result == 42);
    return 0;
}
