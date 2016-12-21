#include "shell.h"

int check_builtins(char **args)
{
	builtins_t builtins[] = {
		{"exit", hosh_exit},
		{"env", hosh_printenv},
		{"unsetenv", hosh_unsetenv},
		{NULL, NULL}
	};
	int i, len;

	len = _strlen(args[0]);
	for (i = 0; builtins[i].name != NULL; i++)
		if (_strncmp(args[0], builtins[i].name, len) == 0)
			return (builtins[i].func(args));
	return (-1);
}
