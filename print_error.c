#include "main.h"

/**
  * print_error - print error message
  * @command: first command line's argument
  */
void print_error(char *command, int istty)
{
	if (!istty)
	{
		write(2, program_name, _strlen(program_name));
		write(2, ": 1: ", 5);
                perror(command);
	}
	else
	{
		write(2, program_name, _strlen(program_name));
                write(2, ": ", 2);
		perror(command);
	}
}
