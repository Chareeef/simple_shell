#include "main.h"

/**
 * execute_command - executes commands
 * @argv: arguments
 * Return: 0 if executed, -1 if not.
 */

int execute_command(char *argv[])
{
	int	id;
	char *invalid = ": Not a valid executable\n";
	struct stat file_info;
	int	istty = 0;

	if (stat(argv[0], &file_info) != 0)
	{
		print_error(argv[0], istty);
		return (-1);
	}

	if (!S_ISREG(file_info.st_mode) || !(file_info.st_mode & S_IXUSR))
	{
		write(2, program_name, _strlen(program_name));
		write(2, ": ", 2);
		write(2, argv[0], _strlen(argv[0]));
		write(2, invalid, _strlen(invalid));
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
