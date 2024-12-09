#include <stdio.h>
#include <stdlib.h>

// struct __attribute__((packed)) T {
struct T {
    char c;
    int i;
    struct T* p;
};

// ce probleme vedeti in codul de mai jos?
// ce dimensiune are structura T (in bytes)?
// ce dimensiune are v1?
// ce dimensiune are v2?

int main(void) {
    struct T* v1 = malloc(5 * sizeof(struct T));

    struct T v2[10];

    printf("size: %lu\n", sizeof(struct T));
    printf("size: %lu\n", sizeof(v1));
    printf("size: %lu\n", sizeof(v2));

    return 0;
}
