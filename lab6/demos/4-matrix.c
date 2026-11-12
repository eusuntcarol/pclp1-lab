#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **a = NULL;
	int n, m, i, j;

	printf("rows cols: ");
	scanf("%d %d", &n, &m);
	if (n < 1 || m < 1)
		return 1;

	a = malloc(n * sizeof(*a));
	if (a == NULL)
		return 1;

	for (i = 0; i < n; i++) {
		a[i] = malloc(m * sizeof(**a));
		if (a[i] == NULL) {
			/* free what was allocated so far */
			for (j = 0; j < i; j++)
				free(a[j]);
			free(a);
			return 1;
		}
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = i * 10 + j;

	for (i = 0; i < n; i++) {
		printf("a[%d] = %p:", i, (void *)a[i]);
		for (j = 0; j < m; j++)
			printf(" %3d", a[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);

	return 0;
}
