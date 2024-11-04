#include <stdio.h>

int a = 10;

void f(int **p) {
    *p += 10;
}

int main(void) {
    int *p = &a;

    f(p);

    if (p == a && *p == &a && a == 20) {
        printf("you got this! :)\n");
    } else {
        printf("try again! :(\n");
    }

    return 0;
}
