#include <stdio.h>

#define NMAX 100

/* No [] in this function. */
int sum(int *v, int n)
{
	/* TODO */
	return 0;
}

int main(void)
{
	int v[NMAX];
	int n, i;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1 || n > NMAX)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	printf("sum = %d\n", sum(v, n));

	return 0;
}
