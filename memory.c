#include "shell.h"

/**
 * smart_alloc - allocate space if there is any, and add memory
 * to list of space to free
 *
 * @size: size of space to allocate
 *
 * Return: pointer to space in memory
 */
void *smart_alloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		_puts("We used up all the memory!!! Holy shit\n");
		exit(20);
	}
	return (ptr);
}
