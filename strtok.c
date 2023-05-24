#include "main.h"

/**
 * _strtok - tokenize a string to smaller strings based on specified delimiters
 * @str: the string to tokenize
 * @delims: string of the specified delimiters
 *
 * Return: a pointer to the next token
 */

char	*_strtok(char *str, char *delims)
{
	static char duplicated[1024];
	static int track = 1;
	static int not_yet = 1;
	int i, j, found, previous_track;

	if (str)
	{
		track = 0;
		not_yet = 1;
		for (i = 0; i < 1024; i++)
			duplicated[i] = '\0';
		_strncpy(duplicated, str, 1024);
		while (duplicated[track] == ' ')
			track++;
	}
	if (!not_yet)
		return (NULL);
	previous_track = track;
	found = 0;
	for (i = track; !found && duplicated[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			while (duplicated[i] == delims[j])
			{
				duplicated[i] = '\0';
				found = 1;
				track = i + 1;
				if (!delims[j + 1] && duplicated[i] != delims[j])
				break;
			}
		}
		if (duplicated[i + 1] == '\0')
			not_yet = 0;
	}
	return (&duplicated[previous_track]);
}
