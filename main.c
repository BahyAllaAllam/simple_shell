#include "main.h"

/**
 * main - main
 * @ac: ac
 * @av: av
 *
 * Return: 0 or 1
*/
int main(int ac, char **av)
{
	info_s in[] = { INFO_INIT };
	int x = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (x)
		: "r" (x));

	if (ac == 2)
	{
		x = open(av[1], O_RDONLY);
		if (x == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				e_put_s(av[0]);
				e_put_s(": 0: Can't open ");
				e_put_s(av[1]);
				e_put_char('\n');
				e_put_char(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		in->rfd = x;
	}
	pop_env_lis(in);
	rea_his(in);
	hsh(in, av);
	return (EXIT_SUCCESS);
}

