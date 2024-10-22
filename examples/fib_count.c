#include <stdio.h>

long long fib_rec(int n, int *count) {
    *count += 1;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fib_rec(n - 1, count) + fib_rec(n - 2, count);
}

long long fib_iter(int n) {
    long long a = 0;
    long long b = 1;

    for (int i = 2; i <= n; ++i) {
        long long c = a + b;

        a = b;
        b = c;
    }

    return b;
}

int main(void) {
    int n = 0;

    scanf("%d", &n);

    // long long res = fib_iter(n);
    int count = 0;
    long long res = fib_rec(n, &count);

    printf("%lld\n", res);
    printf("fib_rec(%d) called %d times\n", n, count);

    return 0;
}