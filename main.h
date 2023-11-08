#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>


#define MAX_COMMAND_LENGTH 100
extern char **environ;

void run_command(char *command, char **argv);
/*void _exit(char *code);*/


/********** Utilities commands ***********/
char *find_path(char *filename);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);


/********** Builtin commands *************/
void set_env(char **argv);
void unset_env (char **argv);
void print_env();





#endif
