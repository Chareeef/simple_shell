#include "main.h"

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: Pointer to duplicated string, or NULL if any error.
 */
char *_strdup(char *str)
{
	char *s;
	int i;

	if (str == NULL)
		return (NULL);
	s = (char *) malloc((_strlen(str) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

int	_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if identical, or the difference between
 * the two first different characters.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
