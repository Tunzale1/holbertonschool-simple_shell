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


/**
 * executable - Execute a file if it has executable permissions
 *
 * @argv: Path to the executable file
 * @input: Input put by the user of this shell
 *
 * Return: no return, void function
 */

void executable(char *argv[], char *input)
{
	int status;
	int status_exit;
	pid_t child;


	if (access(argv[0], X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(argv[0]);
		exit(127);
	}
	child = fork();

	if (child == -1)
	{
		perror("Fail Fork\n");
		exit(0);
	}
	else if (child == 0)
	{
		execve(argv[0], argv, environ);
		free(argv[0]);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status_exit = WEXITSTATUS(status);
			if (status_exit != 0)
			{
				free(argv[0]);
				free(input);
				exit(2);
			}
		}
	}
}


/*
void _execve(char **array)
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

*/

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

		executable(tokens, input);

		free_array(array);
		free(buf);
	}
	return (0);
}
