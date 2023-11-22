#include "main.h"

/**
 * strn_cpy - strncpy
 * @s1: s1
 * @s2: s2
 * @count: count
 * Return: str
*/
char *strn_cpy(char *s1, char *s2, int count)
{
	int i = 0, x;
	char *p = s1;

	while (s2[i] != '\0' && i < count - 1)
	{
		s1[i] = s2[i];
		i++;
	}
	if (i < count)
	{
		x = i;
		while (x < count)
		{
			s1[x] = '\0';
			x++;
		}
	}
	return (p);
}

/**
 * strn_cat - strncat
 * @s1: s1
 * @s2: s2
 * @count: count
 * Return: str
*/
char *strn_cat(char *s1, char *s2, int count)
{
	int i = 0, x = 0;
	char *p = s1;

	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0' && x < count)
	{
		s1[i] = s2[x];
		i++;
		x++;
	}
	if (x < count)
		s1[i] = '\0';
	return (p);
}

/**
 * str_chr - strchr
 * @s1: s1
 * @s2: s2
 * Return: str
*/
char *str_chr(char *s1, char s2)
{
	do {
		if (*s1 == s2)
			return (s1);
	} while (*s1++ != '\0');

	return (NULL);
}
/**
 * str_tow - strtow
 * @s: s
 * @d: deli
 * Return: array
*/
char **str_tow(char *s, char *d)
{
	int i, x, a, o, words_count = 0;
	char **p;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; s[i] != '\0'; i++)
		if (!is_de(s[i], d) && (is_de(s[i + 1], d) || !s[i + 1]))
			words_count++;

	if (words_count == 0)
		return (NULL);
	p = malloc((1 + words_count) * sizeof(char *));
	if (!p)
		return (NULL);
	for (i = 0, x = 0; x < words_count; x++)
	{
		while (is_de(s[i], d))
			i++;
		a = 0;
		while (!is_de(s[i + a], d) && s[i + a])
			a++;
		p[x] = malloc((a + 1) * sizeof(char));
		if (!p[x])
		{
			for (a = 0; a < x; a++)
				free(p[a]);
			free(p);
			return (NULL);
		}
		for (o = 0; o < a; o++)
			p[x][o] = s[i++];
		p[x][o] = 0;
	}
	p[x] = NULL;
	return (p);
}

/**
 * str_tow2 - strtow2
 * @s: str
 * @d: deli
 * Return: array
*/
char **str_tow2(char *s, char d)
{
	int i, x, a, o, words_count = 0;
	char **p;

	if (s == NULL || s[0] == 0)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
		if ((s[i] != d && s[i + 1] == d) ||
		    (s[i] != d && !s[i + 1]) || s[i + 1] == d)
			words_count++;
	if (words_count == 0)
		return (NULL);
	p = malloc((1 + words_count) * sizeof(char *));
	if (!p)
		return (NULL);
	for (i = 0, x = 0; x < words_count; x++)
	{
		while (s[i] == d && s[i] != d)
			i++;
		a = 0;
		while (s[i + a] != d && s[i + a] && s[i + a] != d)
			a++;
		p[x] = malloc((a + 1) * sizeof(char));
		if (!p[x])
		{
			for (a = 0; a < x; a++)
				free(p[a]);
			free(p);
			return (NULL);
		}
		for (o = 0; o < a; o++)
			p[x][o] = s[i++];
		p[x][o] = 0;
	}
	p[x] = NULL;
	return (p);
}

