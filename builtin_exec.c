#include "main.h"

/**
 * builtin_exec - look for builtin and execute it
 * @args: command line arguments
 * @line: command line
 *
 * Return: 1 if the builtin is found and executed, 0 otherwise
 */

int	builtin_exec(char **args, char *line)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free_all(line, args);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}
	return (0);
}
