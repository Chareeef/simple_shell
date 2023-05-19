#include "main.h"

/**
 * print_error - print error message
 * @commandline: tokenized command line
 * @command: first command line's argument
 * @error: error type
 */
void print_error(char **commandline, char *command, int error)
{
	char *permission_denied = ": Permission denied\n";
	char *not_found = ": not found\n";
	char *illegal_num = ": Illegal number: ";
	static int count_error = 1;

	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	print_number(count_error);
	write(2, ": ", 2);
	write(2, command, _strlen(command));
	if (error == 0)
		write(2, not_found, _strlen(not_found));
	else if (error == 1)
		write(2, permission_denied, _strlen(permission_denied));
	else if (error == 2)
	{
		write(2, illegal_num, _strlen(illegal_num));
		write(2, commandline[1], _strlen(commandline[1]));
		_putchar('\n');
	}

	count_error++;
}
