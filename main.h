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

void token_input(char *input);
void executable(char *argv[], char *input);
char *_getpath(char *cmd);
void print_env(void);
#endif
