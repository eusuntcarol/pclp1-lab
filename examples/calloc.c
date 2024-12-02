#include <stdio.h>

int main(void) {
    int n = 0;

    scanf("%d", &n);

    int *v = calloc(n, sizeof(int));

    if (v == NULL) {
        exit(1);
    }

    // do whatever with the vector

    for (int i = 0; i < 10; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    if (v != NULL) {
        free(v);
    }

    return 0;
}
