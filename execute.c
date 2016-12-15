#include "shell.h"

/**
 * execute the corresponding function or program
 * @args: pointer array of arguments
 *
 * Return: either an executing builtin function or outside program
 */
int execute(char **args)
{
	char *builtin_str[] = {
		"cd",
		"help",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		cd_func,
		help_func,
		exit_func
	};
	int i;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < 3; i++)
		if (_strcmp(args[0], builtin_str[i]) == 0)
		    return ((*builtin_func[i])(args));
	return (launch(args));
}
