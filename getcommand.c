#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *line, *word;
	ssize_t n;

	n = 1024;
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
