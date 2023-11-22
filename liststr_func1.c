#include "main.h"

/**
 * lis_len - lis len
 * @d: head
 *
 * Return: size_t
*/
size_t lis_len(const list_s *d)
{
	size_t i = 0;

	while (d)
	{
		d = d->nex;
		i++;
	}
	return (i);
}
/**
 * li_to_st - li to st
 * @d: head
 *
 * Return: char
*/
char **li_to_st(list_s *d)
{
	list_s *n = d;
	size_t i = lis_len(d), x;
	char **rs;
	char *r;

	if (!d || !i)
		return (NULL);
	rs = malloc(sizeof(char *) * (i + 1));
	if (!rs)
		return (NULL);
	for (i = 0; n; n = n->nex, i++)
	{
		r = malloc(str_len(n->s) + 1);
		if (!r)
		{
			for (x = 0; x < i; x++)
				free(rs[x]);
			free(rs);
			return (NULL);
		}

		r = str_cpy(r, n->s);
		rs[i] = r;
	}
	rs[i] = NULL;
	return (rs);
}
/**
 * pri_lis - pri lis
 * @d: head
 *
 * Return: size_t
*/
size_t pri_lis(const list_s *d)
{
	size_t i = 0;

	while (d)
	{
		put_s(con_num(d->n, 10, 0));
		put_char(':');
		put_char(' ');
		put_s(d->s ? d->s : "(nil)");
		put_s("\n");
		d = d->nex;
		i++;
	}
	return (i);
}
/**
 * nod_sta_wit - nod sta wit
 * @d: node
 * @p: prefix
 * @a: a
 *
 * Return: list_s
*/
list_s *nod_sta_wit(list_s *d, char *p, char a)
{
	char *ptr = NULL;

	while (d)
	{
		ptr = st_wi(d->s, p);
		if (ptr && ((a == -1) || (*ptr == a)))
			return (d);
		d = d->nex;
	}
	return (NULL);
}
/**
 * get_nod_ind - get nod ind
 * @d: head
 * @n: node
 *
 * Return: ssize_t
*/
ssize_t get_nod_ind(list_s *d, list_s *n)
{
	size_t i = 0;

	while (d)
	{
		if (d == n)
			return (i);
		d = d->nex;
		i++;
	}
	return (-1);
}

