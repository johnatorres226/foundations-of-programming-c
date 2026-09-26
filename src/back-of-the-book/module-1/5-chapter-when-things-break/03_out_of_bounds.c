/* Module 1, Chapter 1.5 — When Things Break
 * Reference solution: fill a small heap array and print each value.
 * One approach among many — see ANSWERS.md.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 5;
    int *scores = malloc((size_t) count * sizeof(int));
    if (scores == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        scores[i] = i * 10;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", scores[i]);
    }

    free(scores);
    return 0;
}
