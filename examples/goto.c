#include <stdio.h>

int main(void) {
    int a = 1;

    if (a % 2 == 0) {
        goto even;
    } else {
        goto odd;
    }

even:
    printf("a is even\n");
odd:
    printf("a is odd\n");

// try enter an even number and see what happens
// how to fix it?

    return 0;
}