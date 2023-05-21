#include "main.h"
/**
 * cd - change current directory
 * @commandline: pointer to tokenized command line
 * @new_path: destination directory
 *
 * Return: 0 on Success, -1 otherwise
 */
int	cd(char **commandline, char *new_path)
{
	char	*current = _getenv("PWD");
	char	*previous = _getenv("OLDPWD");
	char	*home = _getenv("HOME");
	char	buff[1040];

	if (!new_path || _strcmp(new_path, "~") == 0
			|| _strcmp(new_path, "~/") == 0)
	{
		chdir(home);
	}
	else if (_strcmp(new_path, "-") == 0)
	{
		chdir(previous);
	}
	else
	{
		if (chdir(new_path) == -1)
		{
			print_error(commandline, commandline[0], 3);
			return (-1);
		}
	}

	_setenv("PWD", getcwd(buff, sizeof(buff)), 1);
	_setenv("OLDPWD", current, 1);

	return (0);
}
