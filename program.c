#include "main.h"

/**
 * execute_command - executes commands
 * @argv: arguments
 * Return: 0
 */

int execute_command(char *argv[])
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
