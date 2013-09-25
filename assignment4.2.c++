#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	char *content;
	struct line *next;
} line;

int main()
{
	char *line = NULL;
	size_t len = 0;

	puts("Enter strings to sort:");
	for ( ; ; ) {
		getline(&line, &len, stdin);
		char *ptr;
		for (ptr = line; *ptr != '\n'; ptr++)
			;
		*ptr = 0;
		printf("%s\n", line);
	}
	return 0;
}