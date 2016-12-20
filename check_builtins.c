#include "shell.h"

int check_builtins(char **args)
{
	builtins_t builtins[] = {
		{"exit", hosh_exit},
		{NULL, NULL}
	};
	int i, len;

	i = 0;
	len = _strlen(args[0]);
	while (builtins[i].name != NULL)
	{
		if (_strncmp(args[0], builtins[i].name, len) == 0)
		{
			if (builtins[i].func(args))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
