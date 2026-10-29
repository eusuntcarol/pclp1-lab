#include <stdio.h>

#define MAX_SIZE 50

int main(void) {
    int x[50];
    int y[MAX_SIZE];
    int z[MAX_SIZE] = {0};
    int w[MAX_SIZE] = {1,2,3};

    printf("%zu\n", sizeof(x)); // why?

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}
