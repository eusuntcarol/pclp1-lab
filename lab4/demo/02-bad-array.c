#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int v[x]; // DO NOT EVER USE THIS, can you tell why?

    printf("%zu\n", sizeof(v));

    return 0;
}
