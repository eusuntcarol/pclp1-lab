#include <stdio.h>

#define NMAX 100

/* No [] and no extra array. */
void reverse(int *v, int n)
{
	/* TODO: int *left = ...; int *right = ...; */
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

	reverse(v, n);

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}
