#include "shell.h"

/**
 * hosh_unsetenv - unset an environment variable
 *
 * @args: argument array
 *
 * Return: 0 if success, -1 if failure
 */
int hosh_unsetenv(char **args)
{
	if (args[1] == NULL)
		return (-1);
	return (_unsetenv(args[1]));
}

/**
 * hosh_exit - exit the current child process & free what must be free'd
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
	else if ((status = _atoi(args[1])) != -1)
	{
		free(args);
		_exit(status);
	}
	else
		_puts("Illegal number\n");
	return (1);
}

/**
 * hosh_printenv - print the list of environment variables
 *
 * Return: void
 */
int hosh_printenv(char **args)
{
	char c;
	int i, j;

	if (args[1] == NULL)
	{
		for (i = 0; environ[i]; i++)
		{
			for (j = 0; environ[i][j]; j++)
			{
				c = environ[i][j];
				_putchar(c);
			}
			_putchar('\n');
		}
		return (0);
	}
	return (-1);
}
