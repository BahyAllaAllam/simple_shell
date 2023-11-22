#include "main.h"

/**
 * mem_set - mem set
 * @ptr: ptr
 * @y: byte
 * @m: amount
 * Return: pointer
*/
char *mem_set(char *ptr, char y, unsigned int m)
{
	unsigned int i;

	for (i = 0; i < m; i++)
		ptr[i] = y;
	return (ptr);
}
/**
 * f_free - f free
 * @s: str
*/
void f_free(char **s)
{
	char **x = s;

	if (!s)
		return;
	while (*s)
		free(*s++);
	free(x);
}
/**
 * re_alloc - realloc
 * @r: ptr
 * @o_s: old size
 * @n_s: new size
 *
 * Return: ptr
*/
void *re_alloc(void *r, unsigned int o_s, unsigned int n_s)
{
	char *s;

	if (!r)
		return (malloc(n_s));
	if (!n_s)
		return (free(r), NULL);
	if (n_s == o_s)
		return (r);

	s = malloc(n_s);
	if (!s)
		return (NULL);

	o_s = o_s < n_s ? o_s : n_s;
	while (o_s--)
		s[o_s] = ((char *)r)[o_s];
	free(r);
	return (s);
}
/**
 * b_free - b free
 * @r: ptr
 *
 * Return: 1 or 0
*/
int b_free(void **r)
{
	if (r && *r)
	{
		free(*r);
		*r = NULL;
		return (1);
	}
	return (0);
}

