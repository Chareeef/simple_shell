#include "main.h"

/**
 * execute_command - executes commands
 * @argv: arguments
 * Return: 0 if executed, -1 if not.
 */

int execute_command(char *argv[])
{
	int	id;
	struct stat file_info;

	if (stat(argv[0], &file_info) != 0)
	{
		print_error(argv[0]);
		return (-1);
	}

	if ((file_info.st_mode & S_IXUSR) == 0)
	{
		print_error(argv[0]);
		return (-1);
	}
	if (S_ISREG(file_info.st_mode) == 0)
	{
		print_error(argv[0]);
		return (-1);
	}

	id = fork();
	if (id == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&id);
	}
	return (0);
}
