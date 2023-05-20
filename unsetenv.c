#include "main.h"

/**
 * _unsetenv - unset variable environement
 * @name: name of the variable
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int i, vars, keylen;
	char *temp = NULL;

	keylen = _strlen(name);

	for (vars = 0; environ[vars]; vars++);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], keylen) == 0 && environ[i][keylen] == '=')
		{
			break;
		}
		if (!environ[i + 1])
		{
			write_error("Inexistant VARIABLE\n");
			return (-1);
		}
	}

	for (; environ[i] != NULL; i++)
	{
		temp = environ[i];
		environ[i] = _strdup(environ[i + 1]);
		if (!environ[i] && environ[i + 1])
		{
			write_error("Allocation Failed\n");
			return (-1);
		}
		free(temp);
	}
	
	free(environ[i]);

	environ = _realloc(environ, vars * sizeof(char *), (vars - 1) * sizeof(char *));

	return (0);
}
