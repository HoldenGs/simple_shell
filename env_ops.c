#include "shell.h"

/**
 * hosh_printenv - print the list of environment variables
 *
 * Return: void
 */
void hosh_printenv(void)
{
	char c;
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			c = environ[i][j];
			_putchar(c);
		}
		_putchar('\n');
	}
}

/**
 * unsetenv - unset an environment variable
 *
 * @name: name of variable
 *
 * Return: 0 on success, -1 on failure
 */
int hosh_unsetenv(char *name)
{
	char **ep;
	int len;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	len = _strlen(name);
	ep = environ;
	while (*ep != NULL)
	{
		if (_strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			while (*ep != NULL)
			{
				*ep = *(ep + 1);
				ep++;
			}
		else
			ep++;
	}
	return (0);
}

/**
 * hosh_setenv - set an environment variable
 *
 * @name: variable name
 * @value: variable value
 * @overwrite: integer determining whether we overwite an existing variable
 *
 * Return: 0 on success, -1 on failure
 */
int hosh_setenv(char *name, char *value, int overwrite)
{
	char *envp, *equals;
	int len;

	equals = "=";
	if (name == NULL || name[0] == '\0' || value == NULL)
		return (-1);
	if (hosh_findenv(name) != NULL && overwrite == 0)
		return (0);
	hosh_unsetenv(name);
	envp = smart_alloc(sizeof(char) * (_strlen(name) + 1));
	envp = _strcpy(envp, name);
	envp = str_concat(envp, equals);
	envp = str_concat(envp, value);
	if (hosh_addenv(envp, name) != 0)
		return (-1);
	return (0);
}

/**
 * hosh_findenv - get the pointer to an environment variable
 *
 * @name: variable name
 *
 * Return: pointer to variable if it exists, or NULL if it doesn't
 */
char *hosh_findenv(char *name)
{
	char **envp;
	int len;

	envp = environ;
	len = _strlen(name);
	while (*envp != NULL)
	{
		if (_strncmp(*envp, name, len) == 0)
			return (*envp);
		envp++;
	}
	return (*envp);
}

/**
 * hosh_addenv - add or modify an environment variable
 *
 * @var: variable and value
 * @name: name of variable to add or modify
 *
 * Return: 0 if success, -1 if failure
 */
int hosh_addenv(char *newvar, char *name)
{
	char **newenv, **newhead;
	size_t i;

	if (hosh_findenv(name) == NULL)
	{
		for (i = 0; environ[i] != NULL; i++);
		newenv = smart_alloc(sizeof(char *) * (i + 2));
		newhead = newenv;
		i = 0;
		while (*environ != NULL)
		{
			*newenv = *environ;
			newenv++;
			environ++;
		}
		*newenv = newvar;
		newenv++;
		*newenv = NULL;
		environ = newhead;
		return (0);
	}
	else
		return (-1);
	return (0);
}
