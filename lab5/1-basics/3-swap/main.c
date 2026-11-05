#include <stdio.h>

void swap_val(int a, int b)
{
	/* TODO */
}

void swap_ptr(int *a, int *b)
{
	/* TODO */
}

void sort3(int *a, int *b, int *c)
{
	/* TODO: sort *a, *b, *c ascending using only swap_ptr */
}

int main(void)
{
	int x = 1, y = 2;
	int a, b, c;

	swap_val(x, y);
	printf("after swap_val: x = %d, y = %d\n", x, y);

	/* TODO: call swap_ptr on x and y and print them */

	printf("Enter 3 numbers: ");
	scanf("%d%d%d", &a, &b, &c);

	sort3(&a, &b, &c);
	printf("Sorted: %d %d %d\n", a, b, c);

	return 0;
}
