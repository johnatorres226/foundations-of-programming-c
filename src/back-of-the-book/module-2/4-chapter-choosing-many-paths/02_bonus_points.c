/* Module 2, Chapter 2.4 — Choosing Many Paths
 * Reference solution for exercises/02_bonus_points.c
 * One approach among many — see PRD.md §10.
 */
int bonus_points(int level) {
    int points = 0;

    switch (level) {
        case 3:
            points += 100;
            /* fallthrough */
        case 2:
            points += 50;
            /* fallthrough */
        case 1:
            points += 10;
            break;
        default:
            points = 0;
            break;
    }

    return points;
}
