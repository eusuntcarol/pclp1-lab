#include <stdio.h>
#include <stdlib.h>

/*
 * Each option triggers one memory error. Run it twice:
 *   gcc -Wall -Wextra -g -fsanitize=address 2-memory-bugs.c -o bugs && ./bugs
 *   gcc -Wall -Wextra -g 2-memory-bugs.c -o bugs && valgrind --leak-check=full ./bugs
 */
int main(void)
{
	int bug;
	int *v = NULL;

	printf("bug (1 leak, 2 out of bounds, 3 use after free, 4 double free): ");
	scanf("%d", &bug);

	v = malloc(4 * sizeof(*v));
	if (v == NULL)
		return 1;

	switch (bug) {
	case 1:
		v = NULL;               /* the only address of the block is lost */
		break;
	case 2:
		v[4] = 1;               /* valid indices: 0..3 */
		break;
	case 3:
		free(v);
		printf("%d\n", v[0]);   /* the block is no longer ours */
		v = NULL;
		break;
	case 4:
		free(v);                /* freed again below */
		break;
	}

	free(v);
	printf("done\n");

	return 0;
}
