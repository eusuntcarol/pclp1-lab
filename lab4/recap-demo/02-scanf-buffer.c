#include <stdio.h>

int main(void) {
    // buffer input: 'a\n'
    // first scanf    ^ reads one character (a)
    // to return to the program execution (because it waits for our input),
    // we need to press ENTER, that adds that '\n' in the buffer
    // thus, the second scanf will read that '\n' left in the buffer
    char a = 'a';

    scanf("%c", &a);
    printf("1. %c\n", a);

    scanf("%c", &a);
    printf("2. %c\n", a);

/*
    // why this works??
    int b = 0;
    scanf("%d", &b);
    printf("3. %c\n", b);

    scanf("%d", &a);
    printf("4. %c\n", a);
*/
}
