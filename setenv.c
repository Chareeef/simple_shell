#include "main.h"

/**
 * _setenv - set or add environment variable
 * @name: environnement variable's name
 * @value: environnement variable's value
 * @overwrite: don't change existing variables if zero
 *
 * Return: 0 on success, -1 otherwise.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, keylen, found;
	char new[_POSIX_NAME_MAX];
	char *temp = NULL;
	int	vars = 0;

	keylen = _strlen(name);
	found = 0;
	for (i = 0; environ[i] != NULL && !found; i++)
	{
		if (_strncmp(name, environ[i], keylen) == 0 && environ[i][keylen] == '=')
		{
			found = 1;
			break;
		}
	}
	new[0] = '\0';
	_strcat(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	if (found && overwrite)
	{
		_strncpy(environ[i], new, _strlen(new) + 1);
		return (0);
	}

	if (!found)
	{
		while (environ[vars] != NULL)
			vars++;
		environ = _realloc(environ, i * sizeof(char *), (vars + 2) * sizeof(char *));
		temp = _strdup(new);
		if (!temp)
		{
			write_error("Allocation Failed\n");
			return (-1);
		}
		environ[vars] = temp;
		environ[vars + 1] = NULL;
	}

	return (0);
}
