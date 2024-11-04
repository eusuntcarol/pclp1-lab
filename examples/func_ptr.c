#include <stdio.h>

void do_something(int a) {
    printf("%d\n", a);
}

int main(void)
{
    void (*f)(int) = do_something;
    
    printf("%p\n", do_something);
    printf("%p\n", &do_something); // same thing, DOAR la functii se aplica
    printf("%p\n", f);
    
    f(314);

    return 0;
}
