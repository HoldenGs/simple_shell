#include "shell.h"

/**
 * _strcmp - compare two strings
 *
 * @s1: first string to compare with @s2
 *
 * @s2: second string from which to compare @s1
 *
 * Return: integer value of characters of @s1 minus character number of @s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == 0)
			return (0);
	}
	return (s1[i] - s2[i]);
}
