#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * _strlen - Count string length.
 * @s: Our string
 *
 * Return: The string length.
 */
int _strlen(char *s)
{
	int len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	return (len);
}

