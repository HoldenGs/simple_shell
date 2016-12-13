#include "shell.h"

/**
 * main - main shell function
 * @ac: argument count
 * @av: pointer array of arguments
 *
 * Return: 0 if success, -1 if failure
 */
int main(int ac, char **av, char **env)
{
	char *line, *word;
	int i;
	ssize_t n;
	char *holder[1024];

	n = 1024;
	line = malloc(sizeof(char) * n);
	while (n)
	{
		printf("$ ");
		n = getline(&line, &n, stdin);
		i = 0;
		while ((word = strtok(line, " ")) != NULL)
		{
			holder[i] = word;
			line = NULL;
			i++;
		}
		if (*holder[0] != '\n')
			print_array(holder, i);
	}
	free(line);
	return (0);
}
