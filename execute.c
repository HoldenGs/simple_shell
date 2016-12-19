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
	int i;

	if (args[0][0] == '/')
		execute(args);
	else
		for (i = 0; args[i] != NULL; i++)
			printf("%s\n", args[i]);
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
	int status;

	pid = fork();
	if (pid == 0)
		status = execve(args[0], args, environ);
	else
		wait(&status);
}
