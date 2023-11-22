#include "main.h"
/**
 * builtin_cd - check the code
 * @args: argument variables
 * Return: Always 1.
 */
int builtin_cd(char **args)
{
	if (args[1] == NULL)
		args[1] = getenv("HOME");
	else if (chdir(args[1]) != 0)
	{
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", args[1]);
		return (1);
	}
	else if (strcmp(args[1], "-") == 0)
		chdir(getenv("OLDPWD"));
	return (1);
}
/**
 * builtin_exit - check the code
 * @args: argument variables
 * Return: Always 1.
*/
int builtin_exit(char **args)
{
	int status_num;

	if (args[1] != NULL)
	{
		status_num = atoi(args[1]);
		if (status_num > 0)
		{
			free_arrays(args);
			exit(status_num);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
			exit(2);
		}
	}
	return (EXIT_SUCCESS);
}
/**
 * str_tok - check the code
 * @str: string
 * @delim: delimiters
 * Return: char
*/
char *str_tok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
/**
 * get_line - check the code
 * @buff: buffer
 * @n: size of buffer
 * @stream: stdin
 * Return: ssize_t
*/
ssize_t get_line(char **buff, size_t *n, FILE *stream)
{
	return (getline(buff, n, stream));
}
/**
 * builtin_env - check the code
 * @env: environment
 * Return: int
*/
int builtin_env(char **env)
{
	unsigned int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (1);
}
