#include "main.h"

/**
  * print_error - print error message
  * @command: first command line's argument
  */
void print_error(char *command)
{
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	print_number(count_error);
	write(2, ": ", 2);
	perror(command);
	count_error++;
}
