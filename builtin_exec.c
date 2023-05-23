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
			status = _atoi(args[1]);
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
	return (0);
}

/**
 * cd_exec - look for builtin and execute it
 * @args: command line arguments
 *
 * Return: 1 if the builtin is found and executed, 0 otherwise
 */

int	cd_exec(char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		i++;
	}
	if (_strcmp(args[0], "cd") == 0)
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
 * _atoi - Convert string to integer
 * @s: The string to convert
 *
 * Return: the converted integer
 */

int	_atoi(char *s)
{
	int n = 0, d = 1, i = 0, m = 1;

	while ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
	{
		if (s[i] == '-')
			m *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n += (s[i] - '0') * d;
		if (d == 100000000)
			n -= 1;
		if (d < 1000000000)
			d *= 10;
		i -= 1;
	}
	if (n > 0 && m == -1)
		n *= m;
	if (d >= 100000000 && n > 0)
		n += 1;
	if (d >= 100000000 && n < 0)
		n -= 1;
	return (n);
}
