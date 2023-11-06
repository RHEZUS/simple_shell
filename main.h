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



int countWords(const char *input);
void splitString(const char *input, char ***words, int *wordCount);
void print_env();
char *find_path(char *filename);
void run_command(char *command, char **argv);
void set_env(char **argv);
void unset_env (char **argv);
/*void _exit(char *code);*/







#endif
