#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>


#define MAX_COMMAND_LENGTH 100

int countWords(const char *input);
void splitString(const char *input, char ***words, int *wordCount);

char *_strtok(char *str, const char *delim);







#endif
