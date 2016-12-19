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
	int n, i;
	size_t size;

	size = 0;
	input = NULL;
	while (1)
	{
		_puts("HoldenGs$ ");
		getline(&input, &size, stdin);
		args = make_args(input);
		output(args);
	}
	free(args);
	free(input);
}
