#include <stdio.h>
#include <string.h>

#define NMAX 32

/*
 * Type the same text twice, for example:  Ana Maria Popescu
 */
int main(void)
{
	char word[NMAX];
	char line[NMAX];
	int c;

	printf("text for scanf: ");
	scanf("%31s", word);
	printf("scanf read  [%s]\n", word);

	/* throgw away the rest of the line, including the '\n' */
	c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();

	printf("text for fgets: ");
	if (fgets(line, NMAX, stdin) == NULL)
		return 1;
	printf("fgets read  [%s]  <- note the newline before ]\n", line);

	line[strcspn(line, "\n")] = '\0';
	printf("without \\n  [%s], length %zu\n", line, strlen(line));

	return 0;
}
