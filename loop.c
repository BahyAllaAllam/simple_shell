#include "main.h"
/**
 * loop - check the code
 * @env: environment
 * Return: void
*/
void loop(char **env)
{
	char *line;
	char **args;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		line = read_line();
		if (!line[0])
		{
			free(line);
			status = 1;
			continue;
		}
		del_comment(line);
		args = split_line(line);
		status = find_commands(args, env);
		free(line);
		free_arrays(args);
	}
}
