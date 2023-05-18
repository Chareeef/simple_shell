#include "main.h"

/**
  * print_error - print error message
  * @command: first command line's argument
  */
void print_error(char *command)
{
	int	tty = 0;
	if (isatty(tty))
	{
		write(2, program_name, _strlen(program_name));
                write(2, ": ", 2);
		perror(command);
	}
	else
	{
		write(2, program_name, _strlen(program_name));
		write(2, ": 1: ", 5);
                perror(command);
	}
}
