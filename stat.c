#include "main.h"

/**
 * find_in_cwd - find files in current working directory
 * @argc: arguments count
 * @argv: arguments vector
 */
void find_in_cwd(int argc, char **argv)
{
	char path[1024];
	struct stat status;
	int i;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		exit(-1);
	}

	i = 1;
	while (i < argc)
	{
		getcwd(path, sizeof(path));
		_strcat(path, "/");
		_strcat(path, argv[i]);
		if (stat(path, &status) == 0)
			printf("%s: Found\n", argv[i]);
		else
			printf("%s: Nothing\n", argv[i]);
		i++;
	}
}
