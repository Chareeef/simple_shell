#include "main.h"

/**
 * _strtok - tokenize a string to smaller strings based on specified delimiters
 * @str: the string to tokenize
 * @delims: string of the specified delimiters
 *
 * Return: a pointer to the next token
 */

char	*_strtok(char *str, char *delims)
{
	static char duplicated[1024];
	static int track = 1;
	static int not_yet = 1;
	int i, j, found, previous_track;

	if (str)
	{
		track = 0;
		not_yet = 1;
		for (i = 0; i < 1024; i++)
			duplicated[i] = '\0';
		_strncpy(duplicated, str, 1024);
	}

	if (!not_yet)
		return (NULL);

	previous_track = track;
	found = 0;

	for (i = track; !found && duplicated[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (duplicated[i] == delims[j])
			{
				duplicated[i] = '\0';
				found = 1;
				track = i + 1;
				break;
			}
		}
		if (duplicated[i + 1] == '\0')
			not_yet = 0;
	}

	return (&duplicated[previous_track]);
}

int main(void)
{
	char *str = "Hi.How are you;my bro?";
	char *str2 = "re.fr.am ing;";
	char *tok = "a";

	printf("%s\n", _strtok(str, " .;"));

	while (tok)
	{
		tok = _strtok(NULL, ", ;");
		if (tok)
			printf("Tooken: %s\n", tok);
	}
	printf("\n\t***\n\n");
	tok = _strtok(str2, " .;");

	printf("Tooken: %s\n", tok);
	while (tok)
	{
		tok = _strtok(NULL, ". ;");
		if (tok)
			printf("Tooken: %s\n", tok);
	}


	return (0);
}

/*
int main()
{
	char	*str = "Hi.How are you;my bro?";
	char	*str2 = "re.fr.am ing;";
	char	delim[] = " ,!.";
	char	*token;
	char	*token1;
	
	token = _strtok(str, delim);	
	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, delim);
	}
	token1 = _strtok(str2, delim);
	while (token1 != NULL)
	{
		printf("%s\n", token1);
		token1 = _strtok(NULL, delim);
	}
	return 0;
}*/
