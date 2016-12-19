#include "shell.h"

/**
 * make_args - make array of pointer arguments
 *
 * @av: argument structure
 *
 * Return: argument list
 */
char **make_args(char *input)
{
	char **args, *arg, *pos, *delims;
	int i, wc;

	pos = NULL;
	delims = " \n";
	i = 0;
	wc = wordcount(input);
	args = smart_alloc(sizeof(char *) * (wc + 1));
	arg = tokenize(input, delims, pos);
	while (arg != NULL)
	{
		args[i] = arg;
		printf("args[i] = %s\n", args[i]);
		arg = tokenize(NULL, delims, pos);
		i++;
	}
	return (args);
}
