#include <stdio.h>

int main(void) {
    char c1 = 'A';
    char c2 = 'B';

    printf("c1: %c (%d), c2: %c (%d)\n", c1, c1, c2, c2);

    int diff = c2 - c1;
    printf("diff: %d\n", diff);

    char c3 = c1 + diff;
    printf("c3: %c (%d)\n", c3, c3);

    return 0;
}
