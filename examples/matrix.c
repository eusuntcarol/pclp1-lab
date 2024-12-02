#include <stdio.h>

int main(void) {
    int n = 0;

    scanf("%d", &n);

    int **mat = malloc(n * sizeof(int *));

    if (mat == NULL) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        mat[i] = malloc (n * sizeof(int));

        if (mat[i] == NULL) {
            exit(1);
        }
    }

    // do whatever with the matrix

    // cleanup
    if (mat != NULL) {
        for (int i = 0; i < n; ++i) {
            if (mat[i] != NULL) {
                free(mat[i]);
            }
        }

        free(mat);
    }

    return 0;
}
