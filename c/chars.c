#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **charptr;
	char *word = "hello";
	int *intptr;
	int number = 1024;
	int number2 = 2048;
	intptr = &number;
	int *newintptr = (int *)malloc(sizeof(number2));
	int *badptr;
	*newintptr = number2;
	*badptr = number2;
	printf("%d\n%d\n%d\n", *intptr, *newintptr, *badptr);
	return 0;
}