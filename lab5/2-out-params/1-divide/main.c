#include <stdio.h>

int divide(int a, int b, int *quot, int *rem)
{
	/* TODO */
	return 0;
}

int main(void)
{
	int a, b, quot, rem;

	printf("a b: ");
	scanf("%d%d", &a, &b);

	if (divide(a, b, &quot, &rem))
		printf("%d = %d * %d + %d\n", a, b, quot, rem);
	else
		printf("Division by 0\n");

	return 0;
}
