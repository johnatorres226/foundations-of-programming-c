/* Module 1, Chapter 1.3 — Variables and Types
 * Tests average(): three ints averaged as a double, fraction kept intact.
 * Floating-point results are never compared with == — see CONTENT.html's
 * "Fractional numbers: float and double" section for why.
 */
#include <assert.h>

double average(int a, int b, int c);

static double abs_diff(double x, double y) {
    double d = x - y;
    if (d < 0) {
        d = -d;
    }
    return d;
}

int main(void) {
    assert(abs_diff(average(3, 6, 9), 6.0) < 1e-9);
    assert(abs_diff(average(0, 0, 0), 0.0) < 1e-9);
    assert(abs_diff(average(10, 20, 30), 20.0) < 1e-9);
    assert(abs_diff(average(1, 2, 2), 5.0 / 3.0) < 1e-9);
    return 0;
}
