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
	int	status, i;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = stat_to_int(args[1]);
			if (status == -1)
			{
				print_error(args, args[0], 2);
				return (1);
			}
			for (i = 0; environ[i]; i++)
				free(environ[i]);
			free(environ);
			free_all(line, args);
			exit(status);
		}
		else
		{
			for (i = 0; environ[i]; i++)
				free(environ[i]);
			free(environ);
			free_all(line, args);
			exit(EXIT_SUCCESS);
		}
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}
	return (0);
}

/**
 * builtin_exec2 - look for builtin and execute it
 * @args: command line arguments
 *
 * Return: 1 if the builtin is found and executed, 0 otherwise
 */

int	builtin_exec2(char **args)
{
	int	i;

	for (i = 1; args[i] != NULL; i++)
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] && args[2])
		{
			_setenv(args[1], args[2], 1);
			return (1);
		}
		else
		{
			write(2, "Usage: setenv VARIABLE VALUE\n", 29);
			return (-1);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] && !args[2])
		{
			_unsetenv(args[1]);
			return (1);
		}
		else
		{
			write(2, "Usage: unsetenv VARIABLE\n", 25);
			return (-1);
		}
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		if (i <= 2)
		{
			cd(args, args[1]);
			return (1);
		}
		else
		{
			write_error("Usage: cd [DIRECTORY]\n");
			return (-1);
		}
	}
	return (0);
}

/**
 * stat_to_int - Convert a status in a string to an integer.
 * @s: The pointer to string to convert
 *
 * Return: A positive integer, -1 if any error
 */

int    stat_to_int(char *s)
{
	int		i;
	unsigned int	status;

	i = 0;
	status = 0;

	if (strcmp(s, "-0") == 0)
		return (0);
	if (s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		while ((s[i] >= '0' && s[i] <= '9'))
		{
			status = status * 10 + s[i] - '0';
			i++;
		}
		if (s[i] == '\0')
		{
			break;
		}
		if ((s[i] < '0' || s[i] > '9'))
		{
			return (-1);
		}
		i++;
	}
	return (status);
}
