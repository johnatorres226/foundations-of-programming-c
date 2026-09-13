/* Harness self-test fixture. Not part of the course. */
#include <assert.h>

int subtract(int a, int b);

int main(void) {
    assert(subtract(5, 3) == 2);
    return 0;
}
