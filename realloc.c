#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr:pointer to previously allocated memory
 * @old_size: previous allocated size
 * @new_size: new allocated size
 *
 * Return: a pointer to the new allocated memory, returns NULL if an error.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;

	if (old_size == new_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);

	if (new_size < old_size)
	{
		_memcpy(new, ptr, new_size);
		free(ptr);
	}
	else if (new_size > old_size)
	{
		_memcpy(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}
