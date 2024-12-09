#include <stdio.h>

int main(void) {
    // you can also do this
    struct {
        int a;
        int b;
        int c;
        int d;
    } s = {30, 40, 100, 200};

    printf("%d %d %d %d\n", s.a, s.b, s.c, s.d);

    // or that
    union {
        int a;
        char b;
    } u = { 41 };

    printf("%d %c\n", u.a, u.b);

    // and not really useful, but you can also do this
    enum {
        A = 30,
        B,
        C = 100,
        D
    };

    printf("%d %d %d %d\n", A, B, C, D);

    // why is it not that useful?
}
