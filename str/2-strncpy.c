#include "main.h"

/**
 * _strncpy - Copy n characters of src to dest
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Characters number
 *
 * Return: The pointer to destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	for (j = 0; src[j] != '\0' && j < n; j++)
	{
		dest[j] = src[j];
	}

	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}


	return (dest);
}
