#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ALIASES 100

extern char **environ;



void run_command(char **argv);
char *find_path(char *filename);
void execute_comand(char **argv);
int run_built_in(char **argv);
int run_aliases(char **argv);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void execute_multiple_commands(char *line);
void handle_comment(char *line);
void execute_single_command(char *command);

/********** Utilities commands ***********/

int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t n);
int _strlen(char *str);
int _atoi(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_getenv(char *var_name);
char *_strchr(const char *str, char c);
char *handle_arguments(char *arg);
/********** Builtin commands *************/

void set_env(char **argv);
void unset_env (char **argv);
void print_env();
void change_dir(char **argv);
void handle_alias(char **argv);
void create_update_alias(char *alias);
void print_all_aliases(void);
void print_alias(char *name);
void print_all_aliases(void);
char *delete_char(char* str, char ch);
char* int_to_string(unsigned long int num);
#endif
