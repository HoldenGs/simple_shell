#include "shell.h"

int check_builtins(char **args)
{
	builtins_t builtins[] = {
		{"exit", hosh_exit},
		{"env", hosh_printenv},
		{NULL, NULL}
	};
	int i, len;

	i = 0;
	len = _strlen(args[0]);
	while (builtins[i].name != NULL)
	{
		if (_strncmp(args[0], builtins[i].name, len) == 0)
			return (builtins[i].func(args));
		i++;
	}
	return (-1);
}
