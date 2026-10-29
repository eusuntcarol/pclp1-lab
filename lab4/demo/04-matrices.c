#include <stdio.h>

#define NMAX 5

int main(void) {
    int m[NMAX][NMAX];
    int n[NMAX][NMAX] = {
        {1,2,3,4},
        {9,7},
        {3},
        //...
    };

    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
