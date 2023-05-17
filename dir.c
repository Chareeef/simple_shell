#include "main.h"
/**
 * getdir - print PATH directories
 */
void	getdir(void)
{
	char	*path;
	char	*token;

	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
