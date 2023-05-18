#include "main.h"

/**
  * printenv - print environement variables
  */
void printenv(void)
{
	char **env;
	int i;

	i = 0;
	env = malloc(sizeof(environ));
	while (environ[i])
	{
		env[i] = _strdup(environ[i]);
		printf("%s\n", env[i]);
		i++;
	}
	env[i] = NULL;

	i = 0;
	while (environ[i])
	{
		i++;
	}
	free(env);
}
