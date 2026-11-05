#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

int main(void)
{
	int a, b, opt;

	/* TODO: array of function pointers with add, sub, mul, divi */

	printf("a b option (0 + | 1 - | 2 * | 3 /): ");
	scanf("%d%d%d", &a, &b, &opt);

	/* TODO: validate opt and division by 0 */

	/* TODO: call the operation through the array, no if/switch on opt */

	return 0;
}
