#include "main.h"
/**
 * read_line - check the code
 *
 * Return: char
*/
char *read_line(void)
{
	char *line = NULL;
	size_t n = 0;

	if (get_line(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
			exit(0);
		else
		{
			perror("./hsh: 1:");
			exit(1);
		}
	}
	del_comment(line);
	if (line == NULL)
		exit(0);
	return (line);
}
