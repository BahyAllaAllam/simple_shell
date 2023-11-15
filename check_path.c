#include "main.h"
/**
 * check_path - check the code
 * @args: argument variables
 * @paths: array of paths
 * Return: char
*/
char *check_path(char **args, char **paths)
{
	char *path;
	int i = 0;
	size_t path_size;

	while (paths[i] != NULL)
	{
		path_size = strlen(paths[i]) + strlen("/") + strlen(args[0]) + 1;
		path = malloc(path_size);
		if (path == NULL)
		{
			free(path);
			free_arrays(paths);
			return (NULL);
		}
		strcpy(path, paths[i]);
		strcat(path, "/");
		strcat(path, args[0]);
		if (access(path, F_OK) == 0)
		{
			free_arrays(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_arrays(paths);
	return (NULL);
}
