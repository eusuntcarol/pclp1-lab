#include <stdio.h>

#define NUM_OPS 2
#define ADD_POS 0
#define MUL_POS 1

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int main(void)
{
	int (*ops[NUM_POS])(int, int) = {add, mul};

	printf("op(3, 4) = %d\n", ops[ADD_POS](3, 4));

	printf("op(3, 4) = %d\n", ops[MUL_POS](3, 4));

	return 0;
}
