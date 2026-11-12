#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int local = 1;
	int n, i;
	int *v = NULL;
	int *z = NULL;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1)
		return 1;

	v = malloc(n * sizeof(*v));
	if (v == NULL) {
		printf("malloc failed\n");
		return 1;
	}

	z = calloc(n, sizeof(*z));
	if (z == NULL) {
		printf("calloc failed\n");
		free(v);
		return 1;
	}

	for (i = 0; i < n; i++)
		v[i] = i * 10;

	printf("&local = %p  (stack)\n", (void *)&local);
	printf("&v     = %p  (stack: the pointer itself)\n", (void *)&v);
	printf("v      = %p  (heap: the block)\n", (void *)v);
	printf("z      = %p  (heap: the block)\n", (void *)z);

	printf("sizeof(v) = %zu, block size = %zu bytes\n",
	       sizeof(v), n * sizeof(*v));

	for (i = 0; i < n; i++)
		printf("v[%d] = %d   z[%d] = %d\n", i, v[i], i, z[i]);

	free(v);
	free(z);
	v = NULL;
	z = NULL;

	return 0;
}
