#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *v = NULL;
	int *tmp = NULL;
	int n = 0, cap = 0, x, i;

	printf("numbers, 0 to stop: ");
	scanf("%d", &x);
	while (x != 0) {
		if (n == cap) {
			cap = (cap == 0) ? 2 : cap * 2;
			/* print the old address before realloc: after it, v may be invalid */
			printf("  grow to %2d: %p -> ", cap, (void *)v);
			tmp = realloc(v, cap * sizeof(*v));
			if (tmp == NULL) {
				free(v);
				return 1;
			}
			printf("%p\n", (void *)tmp);
			v = tmp;
		}
		v[n] = x;
		n++;
		scanf("%d", &x);
	}

	printf("count: %d, capacity: %d\n", n, cap);
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");

	free(v);

	return 0;
}
