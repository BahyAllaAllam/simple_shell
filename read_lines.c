#include "main.h"
/**
 * read_line - check the code
 *
 * Return: char
*/
char *read_line(void)
{
	char *line = NULL;
	size_t n = 0, end = 0, start = 0;

	if (get_line(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		else
		{
			free(line);
			perror("./hsh: 1:");
			exit(2);
		}
	}
	end = strlen(line) - 1;

	while (isspace(line[start]))
		start++;
	while (end > start && isspace(line[end]))
		end--;
	if (start > 0 || end < (strlen(line) - 1))
	{
		memmove(line, line + start, end - start + 1);
		line[end - start + 1] = '\0';
	}
	return (line);
}
