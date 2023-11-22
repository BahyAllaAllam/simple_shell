#include "main.h"

/**
 * ad_no - ad no
 * @h: head
 * @s: str
 * @n: n
 *
 * Return: list_t
*/
list_s *ad_no(list_s **h, const char *s, int n)
{
	list_s *n_h;

	if (!h)
		return (NULL);
	n_h = malloc(sizeof(list_s));
	if (!n_h)
		return (NULL);
	mem_set((void *)n_h, 0, sizeof(list_s));
	n_h->n = n;
	if (s)
	{
		n_h->s = str_dup(s);
		if (!n_h->s)
		{
			free(n_h);
			return (NULL);
		}
	}
	n_h->nex = *h;
	*h = n_h;
	return (n_h);
}
/**
 * ad_no_en - ad no en
 * @h: head
 * @s: s
 * @n: num
 *
 * Return: list_t
*/
list_s *ad_no_en(list_s **h, const char *s, int n)
{
	list_s *n_no, *no;

	if (!h)
		return (NULL);

	no = *h;
	n_no = malloc(sizeof(list_s));
	if (!n_no)
		return (NULL);
	mem_set((void *)n_no, 0, sizeof(list_s));
	n_no->n = n;
	if (s)
	{
		n_no->s = str_dup(s);
		if (!n_no->s)
		{
			free(n_no);
			return (NULL);
		}
	}
	if (no)
	{
		while (no->nex)
			no = no->nex;
		no->nex = n_no;
	}
	else
		*h = n_no;
	return (n_no);
}
/**
 * pri_lis_str - pri lis str
 * @d: header
 *
 * Return: size_t
*/
size_t pri_lis_str(const list_s *d)
{
	size_t i = 0;

	while (d)
	{
		put_s(d->s ? d->s : "(nil)");
		put_s("\n");
		d = d->nex;
		i++;
	}
	return (i);
}
/**
 * del_nod_at_ind - del nod at ind
 * @d: head
 * @x: index
 *
 * Return: 1 or 0
*/
int del_nod_at_ind(list_s **d, unsigned int x)
{
	list_s *n, *p_n;
	unsigned int i = 0;

	if (!d || !*d)
		return (0);

	if (!x)
	{
		n = *d;
		*d = (*d)->nex;
		free(n->s);
		free(n);
		return (1);
	}
	n = *d;
	while (n)
	{
		if (i == x)
		{
			p_n->nex = n->nex;
			free(n->s);
			free(n);
			return (1);
		}
		i++;
		p_n = n;
		n = n->nex;
	}
	return (0);
}
/**
 * fre_lis - fre lis
 * @ptr: ptr
 *
 * Return: Nothing
*/
void fre_lis(list_s **ptr)
{
	list_s *n, *n_n, *d;

	if (!ptr || !*ptr)
		return;
	d = *ptr;
	n = d;
	while (n)
	{
		n_n = n->nex;
		free(n->s);
		free(n);
		n = n_n;
	}
	*ptr = NULL;
}

