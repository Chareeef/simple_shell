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
