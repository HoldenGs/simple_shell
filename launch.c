#include "shell.h"

/**
 * launch - execute a command
 * @args: argument list
 *
 * Return:
 */
int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("shell");
		exit(101);
	}
	else if (pid < 0)
		perror("shell");
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
