#include "main.h"
/**
 * split_line - check the code
 * @line: a line of commands
 * Return: array
*/
char **split_line(char *line)
{
	int bufsize = BUFFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *)), *token = NULL;

	if (!tokens || !line[0])
	{
		free(line);
		free(token);
		return (NULL);
	}

	token = str_tok(line, DELIMITRS);
	while (token != NULL)
	{
		tokens[position] = malloc(strlen(token) + 1);
		if (!tokens[position])
		{
			free(token);
			free(line);
			free_arrays(tokens);
			return (NULL);
		}
		strcpy(tokens[position], token);
		position++;
		token = str_tok(NULL, DELIMITRS);
	}
	tokens[position] = NULL;
	free(token);
	return (tokens);
}
