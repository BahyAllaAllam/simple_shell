#include "main.h"

/**
 * is_cm - is cm
 * @in: info
 * @h: path
 *
 * Return: 1 or 0
*/
int is_cm(info_s *in, char *h)
{
	struct stat st;

	(void)in;
	if (!h || stat(h, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chs - dup chs
 * @str: str
 * @t: start
 * @p: stop
 *
 * Return: char
*/
char *dup_chs(char *str, int t, int p)
{
	static char b[1024];
	int i = 0, a = 0;

	for (a = 0, i = t; i < p; i++)
		if (str[i] != ':')
			b[a++] = str[i];
	b[a] = 0;
	return (b);
}
/**
 * fi_pa - fi pa
 * @in: info
 * @str: str
 * @c: cmd
 *
 * Return: NULL
*/
char *fi_pa(info_s *in, char *str, char *c)
{
	int i = 0, p = 0;
	char *h;

	if (!str)
		return (NULL);
	if ((str_len(c) > 2) && st_wi(c, "./"))
	{
		if (is_cm(in, c))
			return (c);
	}
	while (1)
	{
		if (!str[i] || str[i] == ':')
		{
			h = dup_chs(str, p, i);
			if (!*h)
				str_cat(h, c);
			else
			{
				str_cat(h, "/");
				str_cat(h, c);
			}
			if (is_cm(in, h))
				return (h);
			if (!str[i])
				break;
			p = i;
		}
		i++;
	}
	return (NULL);
}

