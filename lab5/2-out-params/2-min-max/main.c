#include <stdio.h>

#define NMAX 100

void min_max(int *v, int n, int *min, int *max)
{
	/* TODO */
}

int main(void)
{
	int v[NMAX];
	int n, i, mn = 0, mx = 0;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1 || n > NMAX)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	min_max(v, n, &mn, &mx);
	printf("min = %d, max = %d\n", mn, mx);

	return 0;
}
