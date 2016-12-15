#include "shell.h"

/**
 * builtin_count - return the number of builtin commands
 *
 * Return: number of builtin commands
 */
//int builtin_count(void)
//{
//	return (sizeof(builtin_str) / sizeof(char *));
//}

/**
 * cd - change directory
 * @args: pointer array of arguments
 *
 * Return: 1 if success, else error
 */
int cd_func(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "You need to give cd an argument\n");
	else
		if (chdir(args[1] != 0))
		    perror("shell");
	return (1);
}

/**
 * help - print out helpful instructions
 * @args: pointer array of arguments
 *
 * Return: 1 if success, else error
 */
int help_func(char **args)
{
	int i;
	printf("Holden Grissett & Corbin Coleman's shell\n");
	printf("Type in commands with arguments, then hit enter\n");
	printf("Operates similarly to bash\n");
	printf("These commands are built in to the shell:\n");
	i = 0;
	while (i < builtin_count())
	{
		printf(" - %s\n", builtin_str[i]);
		i++;
	}
	printf("Use `man [command]` to get info on specific commands\n");
	return (1);
}

/**
 * exit - exit the shell
 * @args: pointer array of arguments
 *
 * Return: 0
 */
int exit_func(char **args)
{
	return (0);
}
