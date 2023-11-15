#include "main.h"
/**
 * main - init function
 * @ac: arguments count
 * @av: arguments variables
 * @env: environment
 * Return: Always 0.
*/
int main(int ac, char **av, char **env)
{
	int x = 2;

	if (ac == 2)
	{
		x = open(av[1], O_RDONLY);
		if (x == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				fprintf(stderr, "%s: 0: Can't open %s\n", av[0], av[1]);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}
	loop(env);
	return (EXIT_SUCCESS);
}
