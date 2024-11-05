#include <stdio.h>

void punning(int *x) {
    char *p = (char *) x;

    for (int i = 0; i < sizeof(int); ++i) {
        printf("%d ", p[i]);
    }
}

int main(void) {
    int a = 259;
    // big endian:    00000000 00000000 00000001 00000011
    // little endian: 00000011 00000001 00000000 00000000

    punning(&a);

    printf("\n");

    return 0;
}
