#include "main.h"

/**
 * hsh - hsh
 * @in: in
 * @argsv: argsv
 *
 * Return: 0 or 1
*/
int hsh(info_s *in, char **argsv)
{
	ssize_t x = 0;
	int ret = 0;

	while (x != -1 && ret != -2)
	{
		cle_in(in);
		if (inter_active(in))
			put_s("$ ");
		e_put_char(BUF_FLUSH);
		x = ge_in(in);
		if (x != -1)
		{
			set_in(in, argsv);
			ret = fi_bu_in(in);
			if (ret == -1)
				fi_cm(in);
		}
		else if (inter_active(in))
			put_char('\n');
		fre_in(in, 0);
	}
	wri_his(in);
	fre_in(in, 1);
	if (!inter_active(in) && in->s)
		exit(in->s);
	if (ret == -2)
	{
		if (in->e_n == -1)
			exit(in->s);
		exit(in->e_n);
	}
	return (ret);
}

/**
 * fi_bu_in - fi_bu_in
 * @in: in
 *
 * Return: int
*/
int fi_bu_in(info_s *in)
{
	int i, ret = -1;
	bu_in_ta tbl[] = {
		{"exit", my_exit},
		{"env", my_env},
		{"help", my_help},
		{"history", my_hist},
		{"setenv", my_set_env},
		{"unsetenv", my_unset_env},
		{"cd", my_cd},
		{"alias", my_alias},
		{NULL, NULL}
	};

	for (i = 0; tbl[i].t; i++)
		if (str_cmp(in->argv[0], tbl[i].t) == 0)
		{
			in->l_c++;
			ret = tbl[i].f(in);
			break;
		}
	return (ret);
}

/**
 * fi_cm - fi_cm
 * @in: in
 *
 * Return: Nothing
*/
void fi_cm(info_s *in)
{
	char *p = NULL;
	int i, x;

	in->pa = in->argv[0];
	if (in->l_c_f == 1)
	{
		in->l_c++;
		in->l_c_f = 0;
	}
	for (i = 0, x = 0; in->ar[i]; i++)
		if (!is_de(in->ar[i], " \t\n"))
			x++;
	if (!x)
		return;

	p = fi_pa(in, get_env(in, "PATH="), in->argv[0]);
	if (p)
	{
		in->pa = p;
		fo_cm(in);
	}
	else
	{
		if ((inter_active(in) || get_env(in, "PATH=")
			|| in->argv[0][0] == '/') && is_cm(in, in->argv[0]))
			fo_cm(in);
		else if (*(in->ar) != '\n')
		{
			in->s = 127;
			pr_er(in, "not found\n");
		}
	}
}

/**
 * fo_cm - fo_cm
 * @in: in
 *
 * Return: Nothing
*/
void fo_cm(info_s *in)
{
	pid_t ch_pi;

	ch_pi = fork();
	if (ch_pi == -1)
	{
		perror("Error:");
		return;
	}
	if (ch_pi == 0)
	{
		if (execve(in->pa, in->argv, ge_en(in)) == -1)
		{
			fre_in(in, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(in->s));
		if (WIFEXITED(in->s))
		{
			in->s = WEXITSTATUS(in->s);
			if (in->s == 126)
				pr_er(in, "Permission denied\n");
		}
	}
}

