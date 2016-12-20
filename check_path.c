#include "shell.h"

/**
 * check_path - Check the path for the given file and if found
 * replaces command argument with new full file name
 * @commands: Pointer array holding command & all command args
 *
 * Return: Pointer array to commands w/ first command replaced
 * if the file was found, or the orginal commands, if not found
 */
char **check_path(char **commands)
{
	char *filename, *delim, *pos, *path, *dir;
	struct stat st;

	pos = NULL;
	delim = ":";
	path = _getenv("PATH");
	if (path == NULL)
	{
		_puts("Uh oh! Couldn't find the PATH!\n");
		_exit(22);
	}
	dir = tokenize(path, delim, &pos);
	while (dir != NULL)
	{
		filename = _strcat(dir, commands[0]);
		if (stat(filename, &st) == 0)
		{
			commands[0] = filename;
			free(path);
			return (commands);
		}
		dir = tokenize(NULL, delim, &pos);
	}
	free(path);
	free(filename);
	return (commands);
}

/**
 * _getenv - Find the value of a given environment variable
 * @name: Name of the environment variable
 *
 * Description: This was built specifically for use with check_path
 * function. May need to be removed or changed based on Holden's code
 *
 * Return: Pointer to the value of the variable if variable found,
 * NULL if no variable found with given name
 */
char *_getenv(char *name)
{
	char *value;
	int i, j;

	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] == name[j])
			j++;
		if (environ[i][j] == '=' && name[j] == '\0')
		{
			value = _strdup(&environ[i][j + 1]);
			return (value);
		}
		i++;
	}
	return (NULL);
}
