#include "main.h"

/**
 * inter_active - interactive
 * @in: info
 *
 * Return: 1 or 0
*/
int inter_active(info_s *in)
{
	return (isatty(STDIN_FILENO) && in->rfd <= 2);
}
/**
 * is_de - is deli
 * @r: char
 * @d: deli
 * Return: 1 or 0
*/
int is_de(char r, char *d)
{
	while (*d)
		if (*d++ == r)
			return (1);
	return (0);
}
/**
 * is_alpha - is alpha
 *@r: char
 *Return: 1 or 0
*/
int is_alpha(int r)
{
	if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * at_oi - atoi
 * @r: str
 * Return: 0 or int
*/
int at_oi(char *r)
{
	int i, n = 1, g = 0, t;
	unsigned int u = 0;

	for (i = 0;  r[i] != '\0' && g != 2; i++)
	{
		if (r[i] == '-')
			n *= -1;

		if (r[i] >= '0' && r[i] <= '9')
		{
			g = 1;
			u *= 10;
			u += (r[i] - '0');
		}
		else if (g == 1)
			g = 2;
	}

	if (n == -1)
		t = -u;
	else
		t = u;

	return (t);
}

