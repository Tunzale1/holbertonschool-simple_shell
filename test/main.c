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
	/* char *input, *tokens; */
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
		if (read > 0 && buf[read - 1] == '\n')
		{
			buf[read - 1] = '\0';
		}
		array = token_input(buf);

		execute(array);


	}
	free_array(buf, array);
	return (0);
}
