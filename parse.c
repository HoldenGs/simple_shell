#include "shell.h"

/**
 * parse - parse a string @line using @delim
 * @line: our string pointer
 * @delim: deliminator separating our tokens
 *
 * Return: pointer array of token strings
 */
char **parse(char *line, char *delim)
{
	int bufsize, position;
	char **tokens;
	char *token;

	bufsize = BUFSIZE;
	position = 0;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
		exit(95);
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				exit(96);
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
