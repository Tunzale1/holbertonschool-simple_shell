#include "main.h"

/**
 * free_array - freeing array
 *
 * @arrray - array
 *
 * Return: void
 */


void free_array(char *buf, char **array)
{
	int j = 0;

	while (array != NULL && array[j] != NULL)
	{
		free(array[j]);
		j++;
	}
	free(array);
	free(buf);
}
