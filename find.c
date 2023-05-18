#include "main.h"

/**
 * check_files - looks for files in the current PATH
 * @argc: arguments count
 * @argv: arguments
 */

void	check_files(int argc, char **argv)
{
	int		i;
	char		cwd[1024];
	struct stat	status;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			getcwd(cwd, sizeof(cwd));
			_strcat(cwd, "/");
			_strcat(cwd, argv[i]);
			if (stat(cwd, &status) == 0)
			{
				printf("%s Found\n", argv[i]);
			}
			else
			{
				printf("%s Not Found\n", argv[i]);
			}
			i++;
		}
	}
	else
	{
		printf("Usage: %s filename ...\n", argv[0]);
	}
}
