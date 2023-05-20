#include "main.h"

/**
 * main - Our shell entry point
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line;
	char *path;
	char **tokens_list;

	program_name = av[0];
	environ = dup_environ();
	while (1)
	{
		line = prompt_command();
		if (_strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		tokens_list = split_str_to_arr(line);
		if (builtin_exec(tokens_list, line) || builtin_exec2(tokens_list))
		{
			free_all(line, tokens_list);
			continue;
		}
		if (!_strchr(tokens_list[0], '/'))
		{
			path = search_exec(tokens_list[0]);
			if (path)
			{
				free(tokens_list[0]);
				tokens_list[0] = path;
			}
			else
			{
				print_error(tokens_list, tokens_list[0], 0);
				free(tokens_list[0]);
				continue;
			}
		}
		execute_command(tokens_list);
		free_all(line, tokens_list);
	}

	return (0);
}
