#include <stdio.h>

int main(void) {
    int a = 0;

    switch (a) {
        case 0:
            printf("a is 0\n");
            break;
        case 1:
            printf("a is 1\n");
            // what happens if we remove the break statement?
            // break;
        case 2:
            printf("a is 2\n");
            break;
        default:
            printf("a is not 0\n");
    }

    return 0;
}
