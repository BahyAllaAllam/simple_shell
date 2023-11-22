#include "main.h"

/**
 * e_put_s - eputs
 * @s: str
 *
 * Return: void
*/
void e_put_s(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		e_put_char(s[i]);
		i++;
	}
}
/**
 * e_put_char - eputchar
 * @s: char
 *
 * Return: -1 or 1
*/
int e_put_char(char s)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}
/**
 * pu_fd - put fd
 * @s: char
 * @f: fd
 *
 * Return: 1 or -1
*/
int pu_fd(char s, int f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}
/**
 * pu_s_fd - put s fd
 * @s: str
 * @f: fd
 *
 * Return: int
 */
int pu_s_fd(char *s, int f)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += pu_fd(*s++, f);
	}
	return (i);
}

