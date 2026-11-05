#include <stdio.h>

#define NMAX 10

void f(int v[])
{
	printf("in f:    sizeof(v) = %zu\n", sizeof(v));
}

void g(int *v)
{
	printf("in g:    sizeof(v) = %zu\n", sizeof(v));
}

int main(void)
{
	int v[NMAX] = {0};

	printf("in main: sizeof(v) = %zu\n", sizeof(v));
	f(v);
	g(v);

	return 0;
}
