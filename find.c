#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char **argv)
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
			strcat(cwd, "/");
			strcat(cwd, argv[i]);
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
	return (0);
}
