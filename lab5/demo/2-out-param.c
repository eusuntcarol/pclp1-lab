#include <stdio.h>

void inc_val(int n)
{
	n++;
	printf("  in inc_val: n = %d (copy, address %p)\n", n, (void *)&n);
}

void inc_ptr(int *n)
{
	(*n)++;
	printf("  in inc_ptr: *n = %d (address %p)\n", *n, (void *)n);
}

int main(void)
{
	int x = 5;

	printf("x = %d, address %p\n", x, (void *)&x);
	
	inc_val(x);
	printf("after inc_val: x = %d\n", x);
	return 0;

	inc_ptr(&x);
	printf("after inc_ptr: x = %d\n", x);

	return 0;
}
