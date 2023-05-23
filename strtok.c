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
	static char *duplicated;
	static char *last;
	static char *temp;
	
	int i, j, found;

	if (str)
	{
		duplicated = _strdup(str);
		if (!temp)
			free(temp);
		temp = duplicated;
	}
	if (!duplicated)
		return (NULL);
	last = duplicated;
	found = 0;

	for (i = 0; duplicated[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (duplicated[i] == delims[j])
			{
				duplicated[i] = '\0';
				duplicated = duplicated + i + 1;
				found = 1;
				break;
			}
			else if (!duplicated[i + 1])
			{
				duplicated = NULL;
				return (last);
			}
		}

		if (found)
			break;
	}
	/*if (duplicated == NULL)
		free(temp);*/

	return (last);
}

/*int main(void)
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
	printf("%s\n", _strtok(str2, " .;"));

	while (tok)
	{
		tok = _strtok(NULL, ", ;");
		if (tok)	
			printf("Tooken: %s\n", tok);
	}


	return (0);
}*/


/*int main()
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
