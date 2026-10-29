#include <stdio.h>

int main(void) {
    int a = 0;

    int counter = 0;

    //while(scanf("%d", &a) != EOF) {
    while(scanf("%d", &a) == 1) {
    
        printf("%d. %d\n", ++counter, a);
    }

    printf("out\n");

    return 0;
}
