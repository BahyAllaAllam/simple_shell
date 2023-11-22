#include "main.h"

/**
 * ge_en - get environ
 * @in: info
 *
 * Return: 0
*/
char **ge_en(info_s *in)
{
	if (!in->env || in->e_c)
	{
		in->env = li_to_st(in->e);
		in->e_c = 0;
	}

	return (in->env);
}

/**
 * un_set_env - unset env
 * @in: info
 * @v: var
 *
 * Return: 1 or 0
*/
int un_set_env(info_s *in, char *v)
{
	list_s *n = in->e;
	size_t i = 0;
	char *r;

	if (!n || !v)
		return (0);

	while (n)
	{
		r = st_wi(n->s, v);
		if (r && *r == '=')
		{
			in->e_c = del_nod_at_ind(&(in->e), i);
			i = 0;
			n = in->e;
			continue;
		}
		n = n->nex;
		i++;
	}
	return (in->e_c);
}
/**
 * set_env - set env
 * @in: info
 * @v: var
 * @u: value
 *
 * Return: 0
*/
int set_env(info_s *in, char *v, char *u)
{
	char *b = NULL;
	list_s *n;
	char *r;

	if (!v || !u)
		return (0);

	b = malloc(str_len(v) + str_len(u) + 2);
	if (!b)
		return (1);
	str_cpy(b, v);
	str_cat(b, "=");
	str_cat(b, u);
	n = in->e;
	while (n)
	{
		r = st_wi(n->s, v);
		if (r && *r == '=')
		{
			free(n->s);
			n->s = b;
			in->e_c = 1;
			return (0);
		}
		n = n->nex;
	}
	ad_no_en(&(in->e), b, 0);
	free(b);
	in->e_c = 1;
	return (0);
}

