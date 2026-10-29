#include <stdio.h>

// BAD!
int calls = 0;

int count(int a) {
    //static int calls = 0;
    ++calls;

    if (a == 0) {
        return calls;
    }

    printf("%d\n", a);

    return count(a - 1);
}

int main(void) {
    int calls = count(5);
    
    printf("calls %d\n", calls);

    return 0;
}