#include "main.h"
/**
 * excute_command - check the code
 * @args: argument variables
 * @env: environment
 * Return: 1.
*/
int excute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Error:");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
