#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block
 * @ptr:  pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: size of the new memory block
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i = 0;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		free(ptr);
		return (p);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	while (i < old_size && i < new_size)
	{
		p[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (p);
}

