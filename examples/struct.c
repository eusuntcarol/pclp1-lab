#include <stdio.h>

struct mystruct {
    int a;
    int b;
    int c;
    int d;
};

int main(void)
{
    struct mystruct s = {30, 40, 100, 200};

    printf("%d %d %d %d\n", s.a, s.b, s.c, s.d);

    return 0;
}
