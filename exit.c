#include "shell.h"

/**
 * hosh_exit - exit the current child process & free what must be free'd
 *
 * @args: Double pointer to the command and given args
 *
 * Return: 0 if success, 1 if failure
 */
int hosh_exit(char **args)
{
	int status;

	if (args[1] == NULL)
	{
		free(args);
		_exit(0);
	}
	else if ((status = atoi(args[1])) != -1)
	{
		free(args);
		_exit(status);
	}
	else
		_puts("Illegal number\n");
	return (1);
}
