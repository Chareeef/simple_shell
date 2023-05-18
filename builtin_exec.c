#include "main.h"

/**
 * builtin_exec - look for builtin and execute it
 * @args: command line arguments
 *
 * Return: 1 if the builtin is found and executed, 0 otherwise
 */

int	builtin_exec(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}

	return (0);
}
