#include "shell.h"

/**
 * loop - run the prompt loop
 *
 * Return: void
 */
void loop(void)
{
	char *line;
	char **args;
	int status;

	while (status)
	{
		printf("$ ");
		line = read_line();
		args = parse(line);
		status = execute(args);
		free(line);
		free(args);
	}
}
