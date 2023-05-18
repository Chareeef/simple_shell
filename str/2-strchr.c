#include "main.h"

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

