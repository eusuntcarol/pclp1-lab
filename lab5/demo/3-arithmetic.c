#include <stdio.h>

#define N 4

int main(void)
{
	int v[N] = {10, 20, 30, 40};
	int *p;

	for (p = v; p < v + N; p++)
		printf("p = %p  *p = %d  index = %ld\n",
		       (void *)p, *p, (long)(p - v));

	printf("\nsizeof(int) = %zu, so addresses grow by %zu\n",
	       sizeof(int), sizeof(int));

	return 0;
}
