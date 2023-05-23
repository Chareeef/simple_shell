#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 *
 * Return: The pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j;

	while  (dest[i] != '\0')
	{
		i++;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = src[j];

	return (dest);
}

/**
 * _strchr - Search the first occurence of c in s
 * @s: String within we search
 * @c: The wanted character
 *
 * Return: Pointer to the occurence, NULL otherwise.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != c && s[i] != '\0'; i++)
	{
	}

	if (s[i] != c)
		return (0);
	else
		return (s + i);
}

/**
 * _strlen - Count string length.
 * @s: Our string
 *
 * Return: The string length.
 */
int _strlen(const char *s)
{
	int len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	return (len);
}


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

/**
 * _strcpy - Copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: The destination buffer
 * @src: The source to copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
