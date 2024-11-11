#include <stdio.h>

#define MAX_SIZE 5

int main(void) {
    char check = 0;
    char str[MAX_SIZE];

    gets(str);
    // fgets(str, MAX_SIZE, stdin);

    printf("You entered: %s\n", str);
    // printf("check overflow: %d (%c)\n", check, check);

    return 0;
}
