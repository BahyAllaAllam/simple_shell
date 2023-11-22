#include "main.h"

/**
 * in_bf - in bf
 * @in: info
 * @b: buf
 * @l: len
 *
 * Return: bytes read
 */
ssize_t in_bf(info_s *in, char **b, size_t *l)
{
	ssize_t r = 0;
	size_t l_ptr = 0;

	if (!*l)
	{
		free(*b);
		*b = NULL;
		signal(SIGINT, sig_int_Han);
#if USE_GETLINE
		r = getline(b, &l_ptr, stdin);
#else
		r = get_lin(in, b, &l_ptr);
#endif
		if (r > 0)
		{
			if ((*b)[r - 1] == '\n')
			{
				(*b)[r - 1] = '\0';
				r--;
			}
			in->l_c_f = 1;
			re_co(*b);
			bui_his_lis(in, *b, in->hc++);
			{
				*l = r;
				in->c_b = b;
			}
		}
	}
	return (r);
}
/**
 * ge_in - get input
 * @in: info
 *
 * Return: ssize
*/
ssize_t ge_in(info_s *in)
{
	static char *b;
	static size_t i, x, l;
	ssize_t r = 0;
	char **b_p = &(in->ar), *ptr;

	put_char(BUF_FLUSH);
	r = in_bf(in, &b, &l);
	if (r == -1)
		return (-1);
	if (l)
	{
		x = i;
		ptr = b + i;

		che_cha(in, b, &x, i, l);
		while (x < l)
		{
			if (is_ch(in, b, &x))
				break;
			x++;
		}

		i = x + 1;
		if (i >= l)
		{
			i = l = 0;
			in->c_b_t = CMD_NORM;
		}

		*b_p = ptr;
		return (str_len(ptr));
	}

	*b_p = b;
	return (r);
}
/**
 * r_f - read buf
 * @in: info
 * @b: buf
 * @i: i
 *
 * Return: ssize_t
*/
ssize_t r_f(info_s *in, char *b, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(in->rfd, b, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
/**
 * get_lin - get lin
 * @in: info
 * @p: ptr
 * @len: length
 *
 * Return: int
*/
int get_lin(info_s *in, char **p, size_t *len)
{
	static char b[READ_BUF_SIZE];
	static size_t i, l;
	size_t a;
	ssize_t e = 0, n = 0;
	char *ptr = NULL, *n_ptr = NULL, *m;

	ptr = *p;
	if (ptr && len)
		n = *len;
	if (i == l)
		i = l = 0;

	e = r_f(in, b, &l);
	if (e == -1 || (e == 0 && l == 0))
		return (-1);

	m = str_chr(b + i, '\n');
	a = m ? 1 + (unsigned int)(m - b) : l;
	n_ptr = re_alloc(ptr, n, n ? n + a : a + 1);
	if (!n_ptr)
		return (ptr ? free(ptr), -1 : -1);

	if (n)
		strn_cat(n_ptr, b + i, a - i);
	else
		strn_cpy(n_ptr, b + i, a - i + 1);

	n += a - i;
	i = a;
	ptr = n_ptr;

	if (len)
		*len = n;
	*p = ptr;
	return (n);
}
/**
 * sig_int_Han - sig int han
 * @n: sig num
 *
 * Return: Nothing
*/
void sig_int_Han(__attribute__((unused))int n)
{
	put_s("\n");
	put_s("($) ");
	put_char(BUF_FLUSH);
}

