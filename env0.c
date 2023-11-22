#include "main.h"

/**
 * my_env - my environ
 * @in: info
 *
 * Return: 0
*/
int my_env(info_s *in)
{
	pri_lis_str(in->e);
	return (0);
}

/**
 * get_env - get env
 * @in: info
 * @e: name
 *
 * Return: char
*/
char *get_env(info_s *in, const char *e)
{
	list_s *n = in->e;
	char *r;

	while (n)
	{
		r = st_wi(n->s, e);
		if (r && *r)
			return (r);
		n = n->nex;
	}
	return (NULL);
}

/**
 * my_set_env - my set env
 * @in: info
 * Return: 0
*/
int my_set_env(info_s *in)
{
	if (in->argc != 3)
	{
		e_put_s("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(in, in->argv[1], in->argv[2]))
		return (0);
	return (1);
}

/**
 * my_unset_env - my unset env
 * @in: info
 *
 * Return: 0
*/
int my_unset_env(info_s *in)
{
	int i;

	if (in->argc == 1)
	{
		e_put_s("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= in->argc; i++)
		un_set_env(in, in->argv[i]);

	return (0);
}

/**
 * pop_env_lis - pop env lis
 * @in: info
 *
 * Return: 0
*/
int pop_env_lis(info_s *in)
{
	list_s *n = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ad_no_en(&n, environ[i], 0);
	in->e = n;
	return (0);
}

