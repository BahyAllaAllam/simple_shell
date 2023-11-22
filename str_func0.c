#include "main.h"

/**
 * str_len - str len
 * @str: str
 *
 * Return: int
*/
int str_len(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * str_cmp - str cmp
 * @str1: str1
 * @str2: str2
 *
 * Return: int
*/
int str_cmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * st_wi - starts with
 * @str: string
 * @substr: substring
 *
 * Return: string
*/
char *st_wi(const char *str, const char *substr)
{
	while (*substr)
		if (*substr++ != *str++)
			return (NULL);
	return ((char *)str);
}

/**
 * str_cat - str cat
 * @s1: str destination
 * @s2: str sorce
 *
 * Return: str
*/
char *str_cat(char *s1, char *s2)
{
	char *ptr = s1;

	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = *s2;
	return (ptr);
}

