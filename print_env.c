#include "main.h"

/**
  * printenv - print environement variables
  */

void printenv(void)
{
	char	**env;
	int	i = 0;
	int	count = 0;

	while (environ[count])
		count++;
	env = malloc((count + 1) * sizeof(char *));
	while (environ[i])
	{
		env[i] = _strdup(environ[i]);
		write(1, env[i], _strlen(env[i]));
		_putchar('\n');
		i++;
	}
	env[i] = NULL;

	i = 0;
	while (environ[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
