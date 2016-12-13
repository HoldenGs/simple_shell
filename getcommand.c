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
	ssize_t n;
	listnode_t *head;

	n = 1024;
	head = NULL;
	line = malloc(sizeof(char) * n);
	while (n)
	{
		printf("$ ");
		n = getline(&line, &n, stdin);
		while ((word = strtok(line, " ")) != NULL)
		{
			if (line == NULL)
				putchar(' ');
			printf("%s", word);
			line = NULL;
		}
	}
	free(line);
	return (0);
}
