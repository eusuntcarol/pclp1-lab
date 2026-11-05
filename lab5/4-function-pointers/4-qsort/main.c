#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int cmp_asc(const void *a, const void *b)
{
	/* TODO: convert to const int * and compare */
	return 0;
}

int cmp_desc(const void *a, const void *b)
{
	/* TODO */
	return 0;
}

int main(void)
{
	int v[NMAX];
	int n, i, mode;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1 || n > NMAX)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	printf("mode (1 asc, 2 desc): ");
	scanf("%d", &mode);

	/* TODO: qsort(v, n, sizeof(v[0]), ...); */

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

	/*
	 * Answers:
	 * - why qsort takes sizeof(v[0]):
	 * - why return x - y can be wrong:
	 */

	return 0;
}
