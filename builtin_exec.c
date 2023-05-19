#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */

int    _atoi(char *s)
{
	int		i;
	unsigned int	result;
	int		sign;
	int		j;

	sign = 1;
	i = 0;
	result = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '\n' || s[i] == '\v' || s[i] == '\t'
				|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
			i++;

		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] == '+')
		{
			i++;
		}
		while ((s[i] >= '0' && s[i] <= '9'))
		{
			j = 1;
			result = result * 10 + s[i] - '0';
			i++;
		}
		if (s[i] == '\0' || j == 1)
		{
			break;
		}
		i++;
	}
	return (result * sign);
}

/**
 * builtin_exec - look for builtin and execute it
 * @args: command line arguments
 * @line: command line
 *
 * Return: 1 if the builtin is found and executed, 0 otherwise
 */

int	builtin_exec(char **args, char *line)
{
	int	status;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = _atoi(args[1]);
			free_all(line, args);
			exit(status);
		}
		else
		{
			free_all(line, args);
			exit(EXIT_SUCCESS);
		}
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (1);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		setenv(args[1], args[2], 1);
		if (!args[1] || !args[2])
		{
			write(2, "Usage: setenv VARIABLE VALUE\n", 29);
			return (-1);
		}
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		unsetenv(args[1]);
		if (!args[1])
		{
			write(2, "Usage: unsetenv VARIABLE\n", 25);
			return (-1);
		}
		return (1);
	}
	return (0);
}
