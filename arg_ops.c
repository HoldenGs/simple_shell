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
	delims = " \n\t";
	i = 0;
	wc = wordcount(input);
	args = smart_alloc(sizeof(char *) * (wc + 1));
	arg = tokenize(input, delims, &pos);
	while (arg != NULL)
	{
		args[i] = arg;
		arg = tokenize(NULL, delims, &pos);
		i++;
	}
	args[i] = NULL;
	return (args);
}
