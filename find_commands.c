#include "main.h"
/**
 * find_commands - check the code
 * @args: argument variables
 * @env: environment
 * Return: Always 1.
*/
int find_commands(char **args, char **env)
{
	int i = 0;
	char *builtin_name[] = {"cd", "exit", "env"};
	char *paths = getenv("PATH");
	char *correct_path;

	int (*builtin_func[]) (char **) = {&builtin_cd, &builtin_exit, &builtin_env};
	if (args[0] == NULL)
	{
		free(paths);
		return (1);
	}
	while (i < 3)
	{
		if (strcmp(args[0], builtin_name[i]) == 0 && i != 2)
		{
			return ((*builtin_func[i])(args));
		}
		else if (strcmp(args[0], builtin_name[i]) == 0 && i == 2)
		{
			return ((*builtin_func[i])(env));
		}
		i++;
	}
	if (paths)
	{
		correct_path = check_path(args, split_paths(paths));
		if (correct_path)
		{
			strcpy(args[0], correct_path);
			free(correct_path);
		}
	}
	return (excute_command(args, env));
}
