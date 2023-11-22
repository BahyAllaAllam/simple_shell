#include "main.h"

/**
 * err_at_oi - err at oi
 * @r: str
 *
 * Return: 0 or -1
*/
int err_at_oi(char *r)
{
	int i = 0;
	unsigned long int u = 0;

	if (*r == '+')
		r++;
	for (i = 0;  r[i] != '\0'; i++)
	{
		if (r[i] >= '0' && r[i] <= '9')
		{
			u *= 10;
			u += (r[i] - '0');
			if (u > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (u);
}
/**
 * pr_er - pr er
 * @in: info
 * @r: err str
 *
 * Return: 0 or -1
*/
void pr_er(info_s *in, char *r)
{
	e_put_s(in->fn);
	e_put_s(": ");
	p_d(in->l_c, STDERR_FILENO);
	e_put_s(": ");
	e_put_s(in->argv[0]);
	e_put_s(": ");
	e_put_s(r);
}
/**
 * p_d - print d
 * @t: input
 * @d: fd
 *
 * Return: int
*/
int p_d(int t, int d)
{
	int (*pc)(char) = put_char;
	int i, n = 0;
	unsigned int s, c;

	if (d == STDERR_FILENO)
		pc = e_put_char;
	if (t < 0)
	{
		s = -t;
		pc('-');
		n++;
	}
	else
		s = t;
	c = s;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (s / i)
		{
			pc('0' + c / i);
			n++;
		}
		c %= i;
	}
	pc('0' + c);
	n++;

	return (n);
}
/**
 * con_num - con num
 * @n: n
 * @b: b
 * @f: f
 *
 * Return: char
*/
char *con_num(long int n, int b, int f)
{
	static char *r;
	static char u[50];
	char g = 0;
	char *p;
	unsigned long x = n;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		x = -n;
		g = '-';

	}
	r = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &u[49];
	*p = '\0';

	do	{
		*--p = r[x % b];
		x /= b;
	} while (x != 0);

	if (g)
		*--p = g;
	return (p);
}
/**
 * re_co - re co
 * @ptr: ptr
 *
 * Return: 0
*/
void re_co(char *ptr)
{
	int i;

	for (i = 0; ptr[i] != '\0'; i++)
		if (ptr[i] == '#' && (!i || ptr[i - 1] == ' '))
		{
			ptr[i] = '\0';
			break;
		}
}

