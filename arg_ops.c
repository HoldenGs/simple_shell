#include "shell.h"

/**
 * make_args - make array of pointer arguments
 *
 * @input: User input to be turned into arguments
 *
 * Return: argument list
 */
char **make_args(char *input)
{
	char **args, *arg, *pos, *delims;
	int i, wc;

	pos = NULL;
	delims = "\n\t \r\a";
	i = 0;
	wc = wordcount(input);
	args = smart_alloc(sizeof(char *) * (wc + 1));
	arg = tokenize(input, delims, &pos);
	while (arg != NULL)
	{
		args[i] = arg;
		if (args[i][0] == '#')
			break;
		arg = tokenize(NULL, delims, &pos);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * wordcount - count the number of words in a string
 *
 * @str: string
 *
 * Return: number of words in @str
 */
int wordcount(char *str)
{
	int wc, state, i;

	i = wc = 0;
	state = OUT;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (state == IN)
			{
				state = OUT;
				wc++;
			}
			i++;
			break;
		default:
			state = IN;
			i++;
		}
	}
	return (wc);
}
