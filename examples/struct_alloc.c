#include <stdio.h>
#include <stdlib.h>

struct mystruct {
    int a;
    int b;
    int c;
    int d;
};

typedef struct mystruct orice_t;

int main(void)
{
    orice_t *s2 = malloc(sizeof(orice_t)); 

    // the most important line of the code
    if (s2 == NULL) {
        return 1;
    }

    s2->a = -30;
    s2->b = -40;
    s2->c = -100;
    s2->d = -200;

    printf("%d %d %d %d\n", s2->a, s2->b, s2->c, s2->d);

    // or equivalently
    (*s2).a = 33;
    (*s2).b = 44;
    (*s2).c = 111;
    (*s2).d = 222;

    printf("%d %d %d %d\n", s2->a, s2->b, s2->c, s2->d);

    // but...wait...THIS is actually most important line of the code
    free(s2);

    return 0;
}
