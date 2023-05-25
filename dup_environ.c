#include "main.h"

/**
 * dup_environ - duplicate environ
 *
 * Return: pointer to duplicated environ
 */
char **dup_environ(void)
{
	char **new_environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
		i++;

	new_environ = malloc((i + 2) * sizeof(char *));

	for (i = 0; environ[i] != NULL; i++)
	{
		new_environ[i] = _strdup(environ[i]);
		if (!new_environ[i])
		{
			write_error("Allocation Failed\n");
			return (NULL);
		}
	}
	new_environ[i] = NULL;

	return (new_environ);
}
