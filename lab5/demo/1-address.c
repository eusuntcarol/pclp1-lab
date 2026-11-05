#include <stdio.h>

int main(void)
{
	int x = 5;
	int *p = &x;

	printf("x  = %d\n", x);
	printf("&x = %p\n", (void *)&x);
	printf("p  = %p\n", (void *)p);
	printf("*p = %d\n", *p);
	printf("&p = %p\n", (void *)&p);

	*p = 10;
	printf("\nAfter *p = 10:\n");
	printf("x  = %d\n", x);

	return 0;
}
