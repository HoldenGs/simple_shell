#include "shell.h"

/**
 * hosh_setenv - set an environment variable
 *
 * @name: variable name
 * @args: argument array
 * @overwrite: integer determining whether we overwite an existing variable
 *
 * Return: 0 on success, -1 on failure
 */
int hosh_setenv(char **args)
{
	char *envp;
	int i, j, len;

	if (args[1] == NULL || args[2] == NULL || args[1][0] == '\0')
	{
		_puts("setenv syntax: setenv VARIABLE VALUE\n");
		return (-1);
	}
	_unsetenv(args[1]);
	len = 0;
	for (i = 2; args[i] != NULL; i++)
		for (j = 0; args[i][j] != '\0'; j++, len++)
	envp = smart_alloc(sizeof(char) * (len + i - 1));
	envp = _strcpy(envp, args[1]);
	envp = str_concat(envp, "=");
	for (i = 2; args[i] != NULL; i++)
	{
		envp = str_concat(envp, args[i]);
		if (args[i + 1] != NULL)
			envp = str_concat(envp, " ");
	}
	if (_addenv(envp, args[1]) != 0)
		return (-1);
	return (0);
}

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
