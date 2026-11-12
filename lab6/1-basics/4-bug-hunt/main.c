#include <stdio.h>
#include <stdlib.h>

/* Returns a new array with the squares of the elements of v. */
int *squares(const int *v, int n)
{
	int *s = malloc(n * sizeof(*s));
	int i;

	for (i = 0; i <= n; i++)
		s[i] = v[i] * v[i];

	return s;
}

int main(void)
{
	int *v;
	int *s;
	int n, i;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1)
		return 1;

	v = malloc(n * sizeof(*v));
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	s = squares(v, n);
	free(v);

	for (i = 0; i < n; i++)
		printf("%d^2 = %d\n", v[i], s[i]);

	return 0;
}

/*
 * Bugs found (line, what, fix):
 * 1.
 * 2.
 * 3.
 * 4.
 */
