#include <stdio.h>

#define NMAX 100

int *find(int *v, int n, int x)
{
	/* TODO */
	return NULL;
}

int main(void)
{
	int v[NMAX];
	int n, i, x;
	int *p;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1 || n > NMAX)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	printf("x: ");
	scanf("%d", &x);

	p = find(v, n, x);
	if (p == NULL) {
		printf("not found\n");
		return 0;
	}

	/* TODO: print the index of the first occurrence (p - v) */

	/* TODO extra: all occurrences, calling find from p + 1 */

	return 0;
}
