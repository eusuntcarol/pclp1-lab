#include <stdio.h>

int main(void)
{
	long long msg = 0x0000216F6C6C6548;
	char *p = (char *)&msg;
	
	// int msg[] = { 0x6C6C6548, 0x0000216F };
	// char *p = (char *)msg;
	
	int i = 0;

	printf("%lld\n", msg);

	while (p[i] != '\0') {
		printf("%c", p[i]);
		i++;
	}
	printf("\n");

	printf("%s\n", p);

	return 0;
}
