#include "shell.h"

char **parse(char *input)
{
	char **args, *delims, **pos;
	int i;

	delims = "\n\t ";
	for (i = 0; (args[i] = tokenize(input, delims, pos)) != NULL; i++)
		input = NULL;
	return (args);
}
