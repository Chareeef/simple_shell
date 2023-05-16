#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char **argv)
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
		strcat(path, "/");
		strcat(path, argv[i]);
		if (stat(path, &status) == 0)
			printf("%s: Found\n", argv[i]);
		else
			printf("%s: Nothing\n", argv[i]);
		i++;
	}
	return (0);
}
