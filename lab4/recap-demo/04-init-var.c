#include <stdio.h>

// STOP using global variables, BAD PRACTICE!
int glob1;
int glob2;

int main(void) {
    int local1;
    int local2 = 314;
    
    printf("%d\n", local1);

    return 0;
}
