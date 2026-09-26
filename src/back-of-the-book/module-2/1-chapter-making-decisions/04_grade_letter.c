/* Module 2, Chapter 2.1 — Making Decisions
 * Reference solution for exercises/04_grade_letter.c
 * One approach among many — see PRD.md §10.
 */
char grade_letter(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}
