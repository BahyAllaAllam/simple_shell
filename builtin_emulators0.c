#include "main.h"

/**
 * my_exit - exit
 * @in: in
 *
 * Return: int
 */
int my_exit(info_s *in)
{
	int i;

	if (in->argv[1])
	{
		i = err_at_oi(in->argv[1]);
		if (i == -1)
		{
			in->s = 2;
			pr_er(in, "Illegal number: ");
			e_put_s(in->argv[1]);
			e_put_char('\n');
			return (1);
		}
		in->e_n = err_at_oi(in->argv[1]);
		return (-2);
	}
	in->e_n = -1;
	return (-2);
}

/**
 * my_cd - my cd
 * @in: info
 *
 * Return: 0
*/
int my_cd(info_s *in)
{
	char *c, *ptr, f[1024];
	int n;

	c = getcwd(f, 1024);
	if (!c)
		put_s("TODO: >>getcwd failure emsg here<<\n");
	if (!in->argv[1])
	{
		ptr = get_env(in, "HOME=");
		if (!ptr)
			n = /* TODO: what should this be? */
				chdir((ptr = get_env(in, "PWD=")) ? ptr : "/");
		else
			n = chdir(ptr);
	}
	else if (str_cmp(in->argv[1], "-") == 0)
	{
		if (!get_env(in, "OLDPWD="))
		{
			put_s(c);
			put_char('\n');
			return (1);
		}
		put_s(get_env(in, "OLDPWD=")), put_char('\n');
		n = /* TODO: what should this be? */
			chdir((ptr = get_env(in, "OLDPWD=")) ? ptr : "/");
	}
	else
		n = chdir(in->argv[1]);
	if (n == -1)
	{
		pr_er(in, "can't cd to ");
		e_put_s(in->argv[1]), e_put_char('\n');
	}
	else
	{
		set_env(in, "OLDPWD", get_env(in, "PWD="));
		set_env(in, "PWD", getcwd(f, 1024));
	}
	return (0);
}
/**
 * my_help - my help
 * @in: info
 *
 * Return: 0
*/
int my_help(info_s *in)
{
	char **a;

	a = in->argv;
	put_s("help call works. Function not yet implemented \n");
	if (0)
		put_s(*a);
	return (0);
}
/**
 * my_hist - my history
 * @in: info
 *
 * Return: 0
*/
int my_hist(info_s *in)
{
	pri_lis(in->h);
	return (0);
}

