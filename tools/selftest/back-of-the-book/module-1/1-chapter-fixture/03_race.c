/* Harness self-test fixture. Not part of the course. Exercises the
 * per-exercise sanitizer override (see tests/03_race.sanitize): correct,
 * mutex-protected counting across threads, compiled and run under
 * ThreadSanitizer instead of the course-default AddressSanitizer, which
 * cannot combine with it. */
#include <pthread.h>

#define MAX_THREADS 8

struct job {
    int *counter;
    pthread_mutex_t *lock;
    int increments;
};

static void *worker(void *arg) {
    struct job *j = arg;
    for (int i = 0; i < j->increments; i++) {
        pthread_mutex_lock(j->lock);
        (*j->counter)++;
        pthread_mutex_unlock(j->lock);
    }
    return NULL;
}

int race_count(int num_threads, int increments_per_thread) {
    int counter = 0;
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_t threads[MAX_THREADS];
    struct job jobs[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        jobs[i].counter = &counter;
        jobs[i].lock = &lock;
        jobs[i].increments = increments_per_thread;
        pthread_create(&threads[i], NULL, worker, &jobs[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return counter;
}
