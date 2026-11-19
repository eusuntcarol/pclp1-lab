#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[8] = "hello";

	printf("%s\n", s);
	printf("sizeof = %zu, strlen = %zu\n", sizeof(s), strlen(s));

	s[2] = '\0';

	printf("%s\n", s);
	printf("sizeof = %zu, strlen = %zu\n", sizeof(s), strlen(s));

	return 0;
}
