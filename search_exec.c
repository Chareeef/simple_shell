#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * search_exec -
 */
char	*search_exec(char *first_arg)
{
	char	*env_path;
	char	*path_dir;
	char	*exec_file;
	char	buffer[1024];
	struct stat status;

	env_path = _getenv("PATH");
	path_dir = strtok(env_path, ":");
	while (path_dir != NULL)
	{
		buffer[0] = '\0';
		strcat(buffer, path_dir);
		strcat(buffer, "/");
		strcat(buffer, first_arg);
		exec_file = malloc((strlen(buffer) + 1) * sizeof(char));
		strncpy(exec_file, buffer, strlen(buffer) + 1);
		if (stat(exec_file, &status) == 0)
			return (exec_file);
		path_dir = strtok(NULL, ":");
	}

	free(exec_file);
	return (NULL);
}
