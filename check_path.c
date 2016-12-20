#include "shell.h"

/**
 * check_path - Check the path for the given file and if found
 * replaces command argument with new full file name
 *
 * @commands: Pointer array holding command & all command args
 *
 * Return: Pointer array to commands w/ first command replaced
 * if the file was found, or the orginal commands, if not found
 */
char **check_path(char **args)
{
	char *filename, *delim, *pos, *path, *dir;
	struct stat st;

	pos = NULL;
	delim = ":";
	path = hosh_findenv("PATH");
	if (path == NULL)
	{
		_puts("You have no PATH? What are you, crazy?\n");
		_exit(22);
	}
	dir = tokenize(path, delim, &pos);
	while (dir != NULL)
	{
		filename = path_concat(dir, args[0]);
		if (stat(filename, &st) == 0)
		{
			args[0] = filename;
			return (args);
		}
		dir = tokenize(NULL, delim, &pos);
	}
	free(filename);
	return (args);
}

/**
 * _strcat - combine two strings together with a '/' in between
 *
 * @s1: The string to start the new combined string
 * @s2: The string to attach to the end of new combined string
 *
 * Return: Pointer to the new string
 */
char *path_concat(char *s1, char *s2)
{
        char *s, *p;
        int s1len, s2len;

        s1len = s2len = 0;
        s1len = _strlen(s1);
        s2len = _strlen(s2);
        s = smart_alloc((s1len + s2len + 2) * sizeof(char));
	p = s;
        while (*s1 != '\0')
        {
                *s = *s1;
                s++;
                s1++;
        }
        *s = '/';
        s++;
        while (*s2 != '\0')
        {
                *s = *s2;
                s++;
                s2++;
        }
        *s = '\0';
        return (p);
}
