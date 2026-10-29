#include <stdio.h>

void f() {
    printf("f\n");

    return;
}

void g(void) {
    printf("g\n");

    return;
}

int main(void) {
    f;

    return 0;
}
