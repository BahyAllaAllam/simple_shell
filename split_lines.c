#include "main.h"
/**
 * split_line - check the code
 * @line: a line of commands
 * Return: array
*/
char **split_line(char *line)
{
	int bufsize = BUFFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *)), *token;

	if (!tokens || !line)
		return (NULL);

	token = str_tok(line, DELIMITRS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = str_tok(NULL, DELIMITRS);
	}
	tokens[position] = NULL;
	return (tokens);
}
