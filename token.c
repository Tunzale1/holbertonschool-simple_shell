#include "main.h"

/**
 * token_input - tokenize the input
 *
 * @input - input string to be tokenized
 *
 * Return: tokens
 */


char **token_input(char *input)
{
	char *token = NULL;
	int i = 0;
	char **array = malloc(sizeof(char *) * 1024);

	token = strtok(input, " ");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, "\t\n");
		i++;
	}
	if (array[i] == NULL)
	{
		return (array);
	}
	if (strcmp(array[0], "exit") == 0 && array[1] == NULL)
	{
		free(array[0]);
		exit(0);
	}
	token = strdup(array[0]);
	return (0);
}