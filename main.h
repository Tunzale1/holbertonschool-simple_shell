#ifndef Simple_Shell_H
#define Simple_Shell_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char **token_input(char *input);
void execute(char **array);
char *_getpath(char *cmd);
void print_env(void);
#endif
