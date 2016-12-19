#include "shell.h"

/**
 * execute - execute a command
 *
 * @args:
 *
 * Return: void
 */
void execute(char **input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		status = execve(input[0], input, environ);
	}
	else
		waitpid(pid, &status, 0);
}
