#include <stdio.h>

/* Returns the digits of n (at most 5 digits), with leading zeros. */
int *digits(int n)
{
	int k, d[5];

	for (k = 4; k >= 0; k--) {
		d[k] = n % 10;
		n = n / 10;
	}

	return d;
}

int main(void)
{
	int n, k;
	int *d;

	printf("n: ");
	scanf("%d", &n);

	d = digits(n);

	printf("Digits:");
	for (k = 0; k < 5; k++)
		printf(" %d", d[k]);
	printf("\n");

	/*
	 * Explanation:
	 */

	return 0;
}
