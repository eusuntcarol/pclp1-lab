#include <stdio.h>

int sum(int n) {
    static int sum = 0;

    sum += n;

    return sum;
}

int main(void) {
    int res = 0;

    getchar();

    res = sum(1);
    printf("%d\n", res);

    getchar();

    res = sum(2);
    printf("%d\n", res);

    getchar();

    res = sum(3);
    printf("%d\n", res);

    return 0;
}
