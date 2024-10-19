#include <stdio.h>

int main(void) {
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", i);

        ++i;
    }
    
    // printf("\nafter for i: %d\n", i);

    return 0;
}