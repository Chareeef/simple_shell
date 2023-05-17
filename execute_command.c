#include "main.h"

/**
 * execute_command - executes commands
 * @argv: arguments
 * Return: 0
 */

int execute_command(char *argv[])
{
	int	id;
	/* char	*path; */

	id = fork();
	if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		/*path = _getenv("PATH");
		if (path == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}*/
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
