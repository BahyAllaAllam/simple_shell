#include "main.h"

/**
 * get_his_fil - get his fil
 * @in: info
 *
 * Return: char
*/
char *get_his_fil(info_s *in)
{
	char *f, *r;

	r = get_env(in, "HOME=");
	if (!r)
		return (NULL);
	f = malloc(sizeof(char) * (str_len(r) + str_len(HIST_FILE) + 2));
	if (!f)
		return (NULL);
	f[0] = 0;
	str_cpy(f, r);
	str_cat(f, "/");
	str_cat(f, HIST_FILE);
	return (f);
}
/**
 * wri_his - write history
 * @in: info
 *
 * Return: 1 or -1
*/
int wri_his(info_s *in)
{
	ssize_t f;
	char *a = get_his_fil(in);
	list_s *n = NULL;

	if (!a)
		return (-1);

	f = open(a, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(a);
	if (f == -1)
		return (-1);
	for (n = in->h; n; n = n->nex)
	{
		pu_s_fd(n->s, f);
		pu_fd('\n', f);
	}
	pu_fd(BUF_FLUSH, f);
	close(f);
	return (1);
}
/**
 * rea_his - rea his
 * @in: info
 *
 * Return: int
*/
int rea_his(info_s *in)
{
	int i, t = 0, lc = 0;
	ssize_t f, n, e = 0;
	struct stat x;
	char *b = NULL, *a = get_his_fil(in);

	if (!a)
		return (0);

	f = open(a, O_RDONLY);
	free(a);
	if (f == -1)
		return (0);
	if (!fstat(f, &x))
		e = x.st_size;
	if (e < 2)
		return (0);
	b = malloc(sizeof(char) * (e + 1));
	if (!b)
		return (0);
	n = read(f, b, e);
	b[e] = 0;
	if (n <= 0)
		return (free(b), 0);
	close(f);
	for (i = 0; i < e; i++)
		if (b[i] == '\n')
		{
			b[i] = 0;
			bui_his_lis(in, b + t, lc++);
			t = i + 1;
		}
	if (t != i)
		bui_his_lis(in, b + t, lc++);
	free(b);
	in->hc = lc;
	while (in->hc-- >= HIST_MAX)
		del_nod_at_ind(&(in->h), 0);
	ren_his(in);
	return (in->hc);
}
/**
 * bui_his_lis - bui his lis
 * @in: info
 * @b: b
 * @lc: lc
 *
 * Return: 0
*/
int bui_his_lis(info_s *in, char *b, int lc)
{
	list_s *n = NULL;

	if (in->h)
		n = in->h;
	ad_no_en(&n, b, lc);

	if (!in->h)
		in->h = n;
	return (0);
}
/**
 * ren_his - ren his
 * @in: info
 *
 * Return: int
*/
int ren_his(info_s *in)
{
	list_s *n = in->h;
	int i = 0;

	while (n)
	{
		n->n = i++;
		n = n->nex;
	}
	return (in->hc = i);
}

