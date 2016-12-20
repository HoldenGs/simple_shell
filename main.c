#include "shell.h"

/**
 * main - initialization of shell
 *
 * @ac: argument count
 * @av: array of arguments
 * @env: environment
 *
 * Return: 0 if success, -1 if failure
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	(void)av;
	loop();
	return (0);
}

/**
 * loop - shell prompt loop
 *
 * @env: linked list of environment
 * @fd: pointer to file descriptor
 *
 * Return: 0 if success, -1 if failure
 */
void loop(void)
{
	char *input, **args;
/*	int n, i;*/
	int looped;
	size_t size;

	size = looped = 0;
	input = NULL;
	while (1)
	{
		_puts("HoldenGs$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			if (looped != 0)
			{
				free(args);
			}
			free(input);
			_putchar('\n');
			_exit(0);
		}
		args = make_args(input);
		output(args);
		looped++;
	}
	free(args);
	free(input);
}
