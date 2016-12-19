#include "shell.h"

/**
 * tokenize - Split the given input into tokens, threadsafe
 * @input: String to split
 * @delim: deliminator
 * @saveptr: pointer used to save the location
 *
 * Return: pointer to token
 */
char *tokenize(char *input, const char *delim, char **saveptr)
{
	char *token;
	int i, j, delimfound;

	if (input == NULL)
	{
		if (saveptr == NULL)
			return (NULL);
		input = *saveptr;
	}
	token = input;
	for (i = delimfound = 0; *input; i++, input++)
	{
		for (j = 0; delim[j]; j++)
			if (*input == delim[j])
				delimfound = 1;
		if (delimfound)
			break;
	}
	if (*input == '\0')
		*saveptr = NULL;
	else
		*saveptr = input + 1;
	token[i] = '\0';
	return (token);
}
