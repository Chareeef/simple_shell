#include "main.h"

/**
 * main - Our shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char *path;
	char **tokens_list;

	while (1)
	{
		line = prompt_command();
		if (strcmp(line, "\n") == 0)
			continue;
		tokens_list = split_str_to_arr(line);
		if (builtin_exec(tokens_list))
			continue;
		if (!strchr(tokens_list[0], '/'))
		{
			path = search_exec(tokens_list[0]);
			if (path)
			{
				free(tokens_list[0]);
				tokens_list[0] = path;
			}
			else
			{
				perror("./shell");
				continue;
			}
		}
		execute_command(tokens_list);
		free_all(line, tokens_list);
	}
	free_all(line, tokens_list);
	return (0);
}
