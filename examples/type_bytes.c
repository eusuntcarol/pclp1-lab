#include <stdio.h>

int main(void) {
    long long a = 4294967297;
    int b = a;

    char *c = (char *)&a;

    for (int i = 0; i < sizeof(long long); ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%d", (c[i] >> (7 - j)) & 1);
        }
        printf(" ");
    }
    printf("\n");

    printf("%d\n", b);

    return 0;
}
