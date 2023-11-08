#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>


#define MAX_COMMAND_LENGTH 100
extern char **environ;

void run_command(char *command, char **argv);
char *find_path(char *filename);

/********** Utilities commands ***********/

int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);
int _strlen(char *str);
int _atoi(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_getenv(char *var_name);

/********** Builtin commands *************/

void set_env(char **argv);
void unset_env (char **argv);
void print_env();
void change_dir(char **argv);





#endif
