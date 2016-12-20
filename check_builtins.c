#include "shell.h"

int check_builtins(char **commands)
{
	builtins built_list[] = {
		{"exit", hosh_exit},
		{NULL, NULL}
	};
	int i, len;

	i = 0;
	len = _strlen(commands[0]);
	while (built_list[i].name != NULL)
	{
		if (_strncmp(commands[0], built_list[i].name, len) == 0)
		{
			if (built_list[i].func(commands))
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}
