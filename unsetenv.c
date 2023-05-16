#include "main.h"

/**
 * _unsetenv - unset variable environement
 * @name: name of the variable
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int i, keylen;

	keylen = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], keylen) == 0 && environ[i][keylen] == '=')
		{
			break;
		}
		if (!environ[i + 1])
			return (-1);
	}

	for (; environ[i] != NULL; i++)
	{
		environ[i] = _strdup(environ[i + 1]);
		if (!environ[i] && environ[i + 1])
			return (-1);
	}

	return (0);
}
