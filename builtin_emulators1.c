#include "main.h"

/**
 * un_set_ali_as - unset alias
 * @in: info
 * @s: str
 *
 * Return: 0 or 1
*/
int un_set_ali_as(info_s *in, char *s)
{
	char *ptr, a;
	int n;

	ptr = str_chr(s, '=');
	if (!ptr)
		return (1);
	a = *ptr;
	*ptr = 0;
	n = del_nod_at_ind(&(in->alias),
		get_nod_ind(in->alias, nod_sta_wit(in->alias, s, -1)));
	*ptr = a;
	return (n);
}
/**
 * set_ali_as - set alias
 * @in: info
 * @s: str
 *
 * Return: 0 or 1
*/
int set_ali_as(info_s *in, char *s)
{
	char *ptr;

	ptr = str_chr(s, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (un_set_ali_as(in, s));

	un_set_ali_as(in, s);
	return (ad_no_en(&(in->alias), s, 0) == NULL);
}
/**
 * pri_ali - print alias
 * @n: node
 *
 * Return: 0 or 1
*/
int pri_ali(list_s *n)
{
	char *ptr = NULL, *c = NULL;

	if (n)
	{
		ptr = str_chr(n->s, '=');
		for (c = n->s; c <= ptr; c++)
			put_char(*c);
		put_char('\'');
		put_s(ptr + 1);
		put_s("'\n");
		return (0);
	}
	return (1);
}
/**
 * my_alias - my alias
 * @in: info
 *
 * Return: 0
*/
int my_alias(info_s *in)
{
	int i = 0;
	char *ptr = NULL;
	list_s *n = NULL;

	if (in->argc == 1)
	{
		n = in->alias;
		while (n)
		{
			pri_ali(n);
			n = n->nex;
		}
		return (0);
	}
	for (i = 1; in->argv[i]; i++)
	{
		ptr = str_chr(in->argv[i], '=');
		if (ptr)
			set_ali_as(in, in->argv[i]);
		else
			pri_ali(nod_sta_wit(in->alias, in->argv[i], '='));
	}

	return (0);
}

