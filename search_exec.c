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
	struct	stat status;
	int	istty = 0;

	env_path = _strdup(_getenv("PATH"));
	path_dir = strtok(env_path, ":");
	while (path_dir != NULL)
	{
		buffer[0] = '\0';
		_strcat(buffer, path_dir);
		_strcat(buffer, "/");
		_strcat(buffer, first_arg);
		exec_file = malloc((_strlen(buffer) + 1) * sizeof(char));
		_strncpy(exec_file, buffer, _strlen(buffer) + 1);
		if (stat(exec_file, &status) == 0 && access(exec_file, X_OK) == 0)
		{
			if (S_ISREG(status.st_mode))
			{
				free(env_path);
				return (exec_file);
			}
			else
			{
				print_error(first_arg, istty);
			}

		}
		free(exec_file);
		path_dir = strtok(NULL, ":");
	}

	free(env_path);
	return (NULL);
}
