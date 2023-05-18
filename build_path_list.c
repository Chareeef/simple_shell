#include "main.h"

/**
 * build_path_list - builds path list
 * @head: head
 * Return: 1
 */

int build_path_list(PATH_DIR **head)
{
	char	*path = _getenv("PATH");
	char	*dir_name;

	dir_name = _strdup(strtok(path, ":"));
	while (dir_name)
	{
		if (!add_path(head, dir_name))
			return (-1);
		dir_name = _strdup(strtok(NULL, ":"));
	}
	return (1);
}
