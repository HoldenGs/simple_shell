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
 */
void loop(void)
{
	char *input, **args;
	int looped;
	size_t size;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	size = 0;
	looped = 0;
	input = NULL;
	while (1)
	{
		inchild = 0;
		_puts("HoldenGs$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			if (looped != 0)
				free_array(args);
			free(input);
			_putchar('\n');
			_exit(0);
		}
		if (input[0] != '\n' && input[0] != '#')
		{
			args = make_args(input);
			if (check_builtins(args) == -1)
			{
				inchild = 1;
				output(args);
			}
			looped++;
		}
	}
	free_array(args);
	free(input);
}

/**
 * sighandler - Print out the prompt if ctrl-C is hit
 * @sig_num: Unused variable necessary for sighandler function types
 */
void sighandler(int sig_num)
{
	(void)sig_num;
	if (inchild == 0)
		_puts("\nHoldenGs$ ");
	signal(SIGINT, sighandler);
}
