#include "main.h"

/**
 * is_ch - is chain
 * @in: info
 * @buf: buf
 * @ptr: pointer
 *
 * Return: 1 or 0
*/
int is_ch(info_s *in, char *buf, size_t *ptr)
{
	size_t x = *ptr;

	if (buf[x] == '|' && buf[x + 1] == '|')
	{
		buf[x] = 0;
		x++;
		in->c_b_t = CMD_OR;
	}
	else if (buf[x] == '&' && buf[x + 1] == '&')
	{
		buf[x] = 0;
		x++;
		in->c_b_t = CMD_AND;
	}
	else if (buf[x] == ';')
	{
		buf[x] = 0;
		in->c_b_t = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = x;
	return (1);
}
/**
 * che_cha - check chain
 * @in: info
 * @buf: buf
 * @ptr: pointer
 * @i: index
 * @l: len
 *
 * Return: Nothing
*/
void che_cha(info_s *in, char *buf, size_t *ptr, size_t i, size_t l)
{
	size_t x = *ptr;

	if (in->c_b_t == CMD_AND)
	{
		if (in->s)
		{
			buf[i] = 0;
			x = l;
		}
	}
	if (in->c_b_t == CMD_OR)
	{
		if (!in->s)
		{
			buf[i] = 0;
			x = l;
		}
	}

	*ptr = x;
}
/**
 * repl_alia - replac alias
 * @in: info
 *
 * Return: 1 or 0
*/
int repl_alia(info_s *in)
{
	int i;
	list_s *n;
	char *ptr;

	for (i = 0; i < 10; i++)
	{
		n = nod_sta_wit(in->alias, in->argv[0], '=');
		if (!n)
			return (0);
		free(in->argv[0]);
		ptr = str_chr(n->s, '=');
		if (!ptr)
			return (0);
		ptr = str_dup(ptr + 1);
		if (!ptr)
			return (0);
		in->argv[0] = ptr;
	}
	return (1);
}
/**
 * repl_vars - replac var
 * @in: info
 *
 * Return: 1 or 0
*/
int repl_vars(info_s *in)
{
	int i = 0;
	list_s *n;

	for (i = 0; in->argv[i]; i++)
	{
		if (in->argv[i][0] != '$' || !in->argv[i][1])
			continue;

		if (!str_cmp(in->argv[i], "$?"))
		{
			repl_stri(&(in->argv[i]),
				str_dup(con_num(in->s, 10, 0)));
			continue;
		}
		if (!str_cmp(in->argv[i], "$$"))
		{
			repl_stri(&(in->argv[i]),
				str_dup(con_num(getpid(), 10, 0)));
			continue;
		}
		n = nod_sta_wit(in->e, &in->argv[i][1], '=');
		if (n)
		{
			repl_stri(&(in->argv[i]),
				str_dup(str_chr(n->s, '=') + 1));
			continue;
		}
		repl_stri(&in->argv[i], str_dup(""));

	}
	return (0);
}
/**
 * repl_stri - replac string
 * @o_ptr: old pointer
 * @n_ptr: new pointer
 *
 * Return: 1 or 0
*/
int repl_stri(char **o_ptr, char *n_ptr)
{
	free(*o_ptr);
	*o_ptr = n_ptr;
	return (1);
}

