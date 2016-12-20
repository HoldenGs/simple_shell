#include "shell.h"

/**
 * ext - exit the current child process & free what must be free'd
 * @commands: Double pointer to the command and given args
 */
void ext(char **commands)
{
	int status;

	if (commands[1] == NULL)
	{
		free(commands);
		_exit(0);
	}
	else if ((status = atoi(commands[1])) != -1)
	{
		free(commands);
		_exit(status);
	}
	else
		_puts("Illegal number\n");
}
