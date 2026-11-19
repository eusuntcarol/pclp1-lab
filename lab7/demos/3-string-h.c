#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[32] = {'\0'};
	s[0] = '\0';

	strcpy(s, "lab");
	strcat(s, " 7");
	printf("%s, length %zu\n", s, strlen(s));

	if (strcmp(s, "lab 7") == 0)
		printf("equal\n");

	return 0;
}
