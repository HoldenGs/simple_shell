#include "shell.h"

/**
 * _strlen - return the length of a string
 *
 * @s: string whose length to return
 *
 * Return: length of @s
 */
int _strlen(char *s)
{
	int n, m = 0;

	while (*(s + m) != '\0')
	{
		++n;
		m++;
	}
	return (n);
}

/**
 * _strdup - return a pointer to a duplicate string of @str
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicate string; NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *a;
	int i, size;


	if (str == NULL)
		return (NULL);
	size = _strlen(str);

	a = smart_alloc((size + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = str[i];
	}
	a[i] = str[i];
	return (a);
}

/**
 * wordcount - count the number of words in a string
 *
 * @str: string
 *
 * Return: number of words in @str
 */
int wordcount(char *str)
{
	int wc, state, i;

	i = wc = 0;
	state = OUT;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (state == IN)
			{
				state = OUT;
				wc++;
			}
			i++;
			break;
		default:
			state = IN;
			i++;
		}
	}
	return (wc);
}
