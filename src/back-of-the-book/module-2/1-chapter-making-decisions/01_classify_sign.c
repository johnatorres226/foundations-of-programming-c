/* Module 2, Chapter 2.1 — Making Decisions
 * Reference solution for exercises/01_classify_sign.c
 * One approach among many — see PRD.md §10.
 */
int classify_sign(int n) {
    if (n < 0) {
        return -1;
    } else if (n > 0) {
        return 1;
    } else {
        return 0;
    }
}
