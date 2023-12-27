#include "main.h"

/**
 * main - simple shell
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buf = NULL;
	char **array;
	size_t bufsize = 0;
	ssize_t read = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		read = getline(&buf, &bufsize, stdin);

		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");

			free(buf);
			break;
		}
		array = token_input(buf);

		execve(array);

		free_array(array);
		free(buf);
	}
	return (0);
}

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


/**
 *_execve - executes a command
 *
 * @array: array 
 *
 * Return: void
 */

void _excecve(char **array)
{
	int status;

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(array[0], array);
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}


/**
 * free_array - freeing array
 *
 * @arrray - array
 *
 * Return: void
 */


void free_array(char **array)
{
	int j = 0;

	while (array != NULL && array[j] != NULL)
	{
		free(array[j]);
		j++;
	}
	free(array);
}
