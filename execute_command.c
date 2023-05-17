#include "main.h"

/**
 * execute_command - executes commands
 * @argv: arguments
 * Return: 0
 */

int execute_command(char *argv[])
{
	int	id;
	struct stat status;
	/* char	*path; */

	if (stat(argv[0], &status) != 0)
	{
		perror("./shell");
		exit(-1);
	}

	id = fork();
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
			perror("./shell");
			exit(-1);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
