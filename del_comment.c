#include "main.h"
/**
 * del_comment - check the code
 * @line: line of commands
 * Return: void
*/
void del_comment(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i - 1] == ' ' && line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
		else if (line[i] == '#' && i == 0)
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}
