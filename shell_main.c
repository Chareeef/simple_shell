#include "main.h"

/**
 * main - Our shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **tokens_list;

	while (1)
	{
		line = prompt_command();
		if (strcmp(line, "\n") == 0)
			continue;
		tokens_list = split_str_to_arr(line);
		if (strcmp(tokens_list[0], "exit") == 0)
		{
			free_all(line, tokens_list);
			exit(EXIT_SUCCESS);
		}
		execute_command(tokens_list);
		free_all(line, tokens_list);
	}
	free_all(line, tokens_list);
       	return (0);
}
