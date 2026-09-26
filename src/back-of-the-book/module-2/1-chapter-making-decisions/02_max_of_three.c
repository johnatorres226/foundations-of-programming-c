/* Module 2, Chapter 2.1 — Making Decisions
 * Reference solution for exercises/02_max_of_three.c
 * One approach among many — see PRD.md §10.
 */
int max_of_three(int a, int b, int c) {
    int largest;

    if (a >= b) {
        if (a >= c) {
            largest = a;
        } else {
            largest = c;
        }
    } else {
        if (b >= c) {
            largest = b;
        } else {
            largest = c;
        }
    }

    return largest;
}
