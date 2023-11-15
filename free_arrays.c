#include "main.h"
/**
 * free_arrays - frees arrays
 * @array: array
 *
 * Return: void
*/
void free_arrays(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
