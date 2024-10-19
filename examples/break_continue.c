#include <stdio.h>

int main(void) {
    int a = 0;

    // continue example
    printf("continue:\n");
    while (a <= 10) {
        if (a % 2 == 0) {
            ++a;
            continue;
        }

        printf("%d\n", a);

        ++a;
    }

    // break example
    printf("\n\n");
    printf("break:\n");
    while (a <= 10) {
        if (a % 2 == 0) {
            ++a;
            break;
        }

        printf("%d\n", a);

        ++a;
    }

    return 0;
}