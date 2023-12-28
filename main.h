#ifndef testMain
#define testMain

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


char **token_input(char *input);
void execute(char **array);
void free_array(char *buf, char **array);
#endif
