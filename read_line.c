#include "shell.h"

/**
 * read_line - read a line from standard input
 *
 * Return: pointer to the input line
 */
char *read_line(void)
{
	char *line;
	size_t bufsize;

	line = NULL;
	bufsize = 0;
	getline(&line, &bufsize, stdin);
	return (line);
}
