#include <stdio.h>

#define NMAX 100

int cmp_asc(int a, int b)
{
	/* TODO */
	return 0;
}

int cmp_desc(int a, int b)
{
	/* TODO */
	return 0;
}

/* Selection sort; the order is decided only by cmp. */
void sort(int *v, int n, int (*cmp)(int, int))
{
	/* TODO */
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

	/* TODO: pick the comparator and call sort */

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}
