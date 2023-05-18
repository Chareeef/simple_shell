#include "main.h"

/**
 * search_exec - look for executable file in the PATH
 * @first_arg: first command line argument
 *
 * Return: the executable file's absolute path, or NULL
 */
char	*search_exec(char *first_arg)
{
	char	*env_path;
	char	*path_dir;
	char	*exec_file;
	char	buffer[1024];
	struct stat status;
	int	i;

	env_path = _strdup(_getenv("PATH"));
	path_dir = strtok(env_path, ":");
	while (path_dir != NULL)
	{
		for (i = 0; i < 1024; i++)
			buffer[i] = '\0';

		strcat(buffer, path_dir);
		strcat(buffer, "/");
		strcat(buffer, first_arg);
		exec_file = malloc((strlen(buffer) + 1) * sizeof(char));
		strncpy(exec_file, buffer, strlen(buffer) + 1);
		if (stat(exec_file, &status) == 0)
			return (exec_file);
		free(exec_file);
		path_dir = strtok(NULL, ":");
	}

	free(env_path);
	return (NULL);
}
