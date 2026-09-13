/* Harness self-test fixture. Not part of the course. */
#include <assert.h>

int race_count(int num_threads, int increments_per_thread);

int main(void) {
    assert(race_count(4, 2000) == 8000);
    return 0;
}
