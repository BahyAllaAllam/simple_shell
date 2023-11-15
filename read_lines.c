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
	del_comment(line);
	if (line == NULL)
		free(line);
	return (line);
}
