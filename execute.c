#include "shell.h"

/**
 * output - decide what to do with @args
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void output(char **args)
{
/*	int i;*/

	if (args[0][0] == '/')
		execute(args);
	else
	{
		args = check_path(args);
		execute(args);
/*		for (i = 0; args[i] != NULL; i++)
		printf("%s\n", args[i]);*/
	}
}

/**
 * execute - execute a program
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		_exit(99);
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("Error");
		_exit(1);
	}
	else
		wait(&status);
}
