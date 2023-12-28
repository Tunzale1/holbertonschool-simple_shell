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
	char *token;
	int i = 0;
	char **array = malloc(sizeof(char *) * 1024);

	token = strtok(input, " ");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, "\t\n");
		i++;
	}
	array[i] = NULL;
	return (array);
}
