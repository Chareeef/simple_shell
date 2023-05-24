#include "main.h"

/**
 * _sigint - signal handler for the SIGINT signal
 * @s: integer
 */

void	_sigint(int s __attribute__((unused)))
{
	write(STDERR_FILENO, "\n#cisfun$ ", _strlen("\n#cisfun$ "));
}
