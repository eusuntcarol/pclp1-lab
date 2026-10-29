#include <stdio.h>

int main(void) {
    int x = 0;

    int cont = scanf("%d", &x);

    while (cont != EOF) {
        // ...
        int cont = scanf("%d", &x);  // Bad: a NEW variable
    }

    return 0;
}
