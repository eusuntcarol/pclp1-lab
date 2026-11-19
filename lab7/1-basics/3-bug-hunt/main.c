#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 32

/* Returns "Hello, <name>!" in a new heap block. The caller frees it. */
char *make_greeting(const char *name)
{
	char *g = malloc(strlen("Hello, ") + strlen(name) + strlen("!"));

	if (g == NULL)
		return NULL;
	strcpy(g, "Hello, ");
	strcat(g, name);
	strcat(g, "!");
	return g;
}

int main(void)
{
	char name[NMAX];
	char tag[NMAX] = "none";
	char *role = "guest";
	char *greeting = NULL;

	printf("name: ");
	scanf("%31s", name);

	/* the tag is the first 3 letters of the name ("none" until set) */
	strncpy(tag, name, 3);

	if (name == "admin")
		role = "admin";

	/* capitalize the role */
	role[0] = role[0] - 'a' + 'A';

	greeting = make_greeting(name);
	if (greeting == NULL)
		return 1;

	printf("%s\n", greeting);
	printf("tag: %s, role: %s\n", tag, role);

	return 0;
}
