#include "main.h"
/**
 * split_paths - check the code
 * @paths: string of paths
 * Return: array
*/
char **split_paths(char *paths)
{
	char *token;
	char **tokens = malloc(BUFFSIZE * sizeof(char *));
	int tokens_num = 0, i = 0;
	char *paths_backup;

	paths_backup = strdup(paths);
	if (tokens == NULL || paths_backup == NULL)
	{
		free(paths_backup);
		free_arrays(tokens);
		return (NULL);
	}
	token = str_tok(paths_backup, ":");
	while (token != NULL)
	{
		tokens[tokens_num] = strdup(token);
		if (tokens[tokens_num] == NULL)
		{
			while (i < tokens_num)
			{
				free(tokens[i]);
				i++;
			}
			free(tokens);
			free(paths_backup);
			free(token);
			return (NULL);
		}
		tokens_num++;
		token = str_tok(NULL, ":");
	}
	tokens[tokens_num] = NULL;
	free(paths_backup);
	free(token);
	return (tokens);
}
