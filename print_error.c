#include "main.h"

/**
 * print_error - print principal error message
 * @commandline: tokenized command line
 * @command: first command line's argument
 * @error: error type
 */
void print_error(char **commandline, char *command, int error)
{
	char *permission_denied = ": Permission denied\n";
	char *not_found = ": not found\n";
	char *illegal_num = ": Illegal number: ";
	char *cd_error = ": can't cd to ";
	static int count_error = 1;

	write_program_name(NULL);
	write_error(": ");
	print_number(count_error);
	write_error(": ");
	write_error(command);
	if (error == 0)
		write_error(not_found);
	else if (error == 1)
		write_error(permission_denied);
	else if (error == 2)
	{
		write_error(illegal_num);
		write_error(commandline[1]);
		_putchar_err('\n');
	}
	else if (error == 3)
	{
		write_error(cd_error);
		write_error(commandline[1]);
		_putchar_err('\n');
	}
	count_error++;
}

/**
 * write_error - write error message into stderr
 * @message: error message
 */
void write_error(char *message)
{
	write(2, message, _strlen(message));
}

/**
 * write_program_name - write program's name into stderr
 * @program_name: program's name
 */
void write_program_name(char *program_name)
{
	static int init_name = 1;
	static int do_not_write = 1;
	static char name[1024];

	if (init_name)
	{
		_strncpy(name, program_name, _strlen(program_name));
		init_name = 0;
	}
	if (!do_not_write)
		write(2, name, _strlen(name));

	do_not_write = 0;
}
