#include <stdio.h>

#define MAX_SIZE 10

int main(void) {
    int v[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        v[i] = i;

        printf("%d\n", v[i]);
    }

    return 0;
}
