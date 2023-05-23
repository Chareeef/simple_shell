#include "main.h"

/**
 * free_all - frees all allocations
 * @line: line
 * @tokens_list: tokens list
 */

void free_all(char *line, char **tokens_list)
{
	int i;

	for (i = 0; tokens_list[i]; i++)
		free(tokens_list[i]);
	free(tokens_list);
	free(line);
}

/**
 * prompt_command - the prompt
 * @void: void
 * Return: line
 */

char *prompt_command(void)
{
	char *line = NULL;
	size_t n = 0;
	int tty = 0, i;

	if (isatty(tty))
		write(1, "#cisfun$ ", _strlen("#cisfun$ "));

	if (getline(&line, &n, stdin) == -1)
	{
		if (isatty(tty))
			_putchar('\n');
		for (i = 0; environ[i]; i++)
			free(environ[i]);
		free(environ);
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(line, "..\n") == 0)
	{
		print_error(NULL, "..", 1);
		free(line);
		return (NULL);
	}
	else if (_strcmp(line, "\n") == 0 || line[0] == '#' ||
			_strcmp(line, ".\n") == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * split_str_to_arr - splits a string
 * @line: line
 * Return: array of each word of the string
 */

char **split_str_to_arr(char *line)
{
	char **tokens_list;
	char *token, *comment;
	int i, num;

	i = 0;
	num = 0;
	comment = _strchr(line, '#');
	if (comment != NULL)
		*comment = '\0';
	while (line[i])
	{
		if ((line[i] == ' ' && line[i + 1] != ' ') || line[i] == '\n')
			num++;
		i++;
	}

	tokens_list = malloc((num + 1) * sizeof(char *));
	token = _strtok(line, " \n");

	i = 0;
	while (token)
	{
		tokens_list[i] = malloc((_strlen(token) + 1) * sizeof(char));
		if (!tokens_list)
		{
			exit(-1);
		}
		_strcpy(tokens_list[i], token);
		token = _strtok(NULL, " \n");
		i++;
	}
	tokens_list[i] = token;
	return (tokens_list);
}
