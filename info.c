#include "main.h"

/**
 * cle_in -cle in
 * @in: info
*/
void cle_in(info_s *in)
{
	in->ar = NULL;
	in->argv = NULL;
	in->pa = NULL;
	in->argc = 0;
}
/**
 * set_in - set in
 * @in: info
 * @v: av
*/
void set_in(info_s *in, char **v)
{
	int i = 0;

	in->fn = v[0];
	if (in->ar)
	{
		in->argv = str_tow(in->ar, " \t");
		if (!in->argv)
		{

			in->argv = malloc(sizeof(char *) * 2);
			if (in->argv)
			{
				in->argv[0] = str_dup(in->ar);
				in->argv[1] = NULL;
			}
		}
		for (i = 0; in->argv && in->argv[i]; i++)
			;
		in->argc = i;

		repl_alia(in);
		repl_vars(in);
	}
}
/**
 * fre_in - fre in
 * @in: info
 * @la: la
*/
void fre_in(info_s *in, int la)
{
	f_free(in->argv);
	in->argv = NULL;
	in->pa = NULL;
	if (la)
	{
		if (!in->c_b)
			free(in->ar);
		if (in->e)
			fre_lis(&(in->e));
		if (in->h)
			fre_lis(&(in->h));
		if (in->alias)
			fre_lis(&(in->alias));
		f_free(in->env);
			in->env = NULL;
		b_free((void **)in->c_b);
		if (in->rfd > 2)
			close(in->rfd);
		put_char(BUF_FLUSH);
	}
}

