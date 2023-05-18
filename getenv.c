#include "main.h"

/**
 * _getenv - get variable environement
 * @key: name of the variable
 *
 * Return: value of the variable or NULL if the variable not found
 */
char	*_getenv(const char *key)
{
	int		i;
	int		keylen;
	char		*ret;

	i = 0;
	keylen = _strlen(key);
	while (environ[i] != NULL)
	{
		if (!_strncmp(environ[i], key, keylen) && environ[i][keylen] == '=')
		{
			ret = _strchr(environ[i], '=');
			if (ret != NULL)
				return (ret + 1);
			else
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
