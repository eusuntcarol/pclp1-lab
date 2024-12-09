#include <stdio.h>

enum myenum {
    A = 30,
    B,
    C = 100,
    D
};

int main(void)
{
    printf("size: %lu\n", sizeof(enum myenum));
    printf("%d %d %d %d\n", A, B, C, D);

    return 0;
}
