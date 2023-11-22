#include "main.h"

/**
 * str_cpy - str cpy
 * @s1: str dest
 * @s2: str source
 *
 * Return: str
*/
char *str_cpy(char *s1, char *s2)
{
	int i = 0;

	if (s1 == s2 || s2 == 0)
		return (s1);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

/**
 * str_dup - str dup
 * @s: str
 *
 * Return: str
*/
char *str_dup(const char *s)
{
	int len = 0;
	char *ptr;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--s;
	return (ptr);
}

/**
 *put_s - puts
 *@s: s
 *
 * Return: void
*/
void put_s(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		put_char(s[i]);
		i++;
	}
}

/**
 * put_char - putchar
 * @s: char
 *
 * Return: int
*/
int put_char(char s)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}

