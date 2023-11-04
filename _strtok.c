#include "main.h"

char *_strtok(char *str, const char *delim)
{
    static char *last_token = NULL;

    if (str == NULL)
    {
        str = last_token;
    }

    while (*str != '\0' && strchr(delim, *str) != NULL)
    {
        str++;
    }

    if (*str == '\0')
    {
        last_token = NULL;
        return NULL;
    }

    char *token_start = str;

    while (*str != '\0' && strchr(delim, *str) == NULL)
    {
        str++;
    }

    if (*str != '\0')
    {
        *str = '\0';
        str++;
    }

    last_token = str;

    return token_start;
}
