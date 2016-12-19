#include "shell.h"

/**
 * tokenize - Split the given input into tokens, threadsafe
 * @input: String to split
 * @delims: deliminator
 * @saveptr: pointer used to save the location
 *
 * Return: pointer to token
 */
char *tokenize(char *input, const char *delims, char *saveptr)
{
	char *token;
	int i, j, indelims;

	if (input == NULL)
	{
		printf("saveptr value = %p\n", saveptr);
		if (saveptr == NULL)
			return (NULL);
		input = saveptr;
	}
	token = make_token(input, delims);
	if (*input != '\0')
	{
		for (indelims = IN; indelims && *input; input++)
		{
			indelims = OUT;
			for (j = 0; delims[j]; j++)
				if (delims[j] == *input)
					indelims = IN;
		}
	}
	saveptr = input + 1;
	printf("save val before = %p\n", saveptr);
	if (*input == '\0')
		saveptr = NULL;
	return (token);
}

/**
 * make_token - make the token for tokenize()
 * @input: input string
 * @delims: deliminators
 * @saveptr: pointer to save position
 *
 * Return: token string
 */
char *make_token(char *input, const char *delims)
{
	char *token;
	int i, j, delimfound;

	for (i = delimfound = 0; input[i]; i++)
	{
		for (j = 0; delims[j]; j++)
			if (delims[j] == input[i])
				delimfound = 1;
		if (delimfound == 1)
			break;
	}
	token = smart_alloc(sizeof(char) * (i + 1));
	for (i = delimfound = 0; *input; input++, i++)
	{
		printf("input[i] = %c\n", *input);
		for (j = 0; delims[j]; j++)
			if (delims[j] == *input)
				delimfound = 1;
		if (delimfound == 1)
			break;
		token[i] = *input;
	}
	token[i] = '\0';
	return (token);
}
