#include "maintest.h"
int main(void)
{
	char *buf = NULL;
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
	}
}
