#include "main.h"

/**
 * print_env - prints the current environmen
 */

void print_env()
{
	char **env = environ;
	while(*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

void set_env(char **argv)
{
	char *name = argv[1];
	char *value = argv[2] == NULL ? " " : argv[2];
	
	if (setenv(name, value, 1) == -1)
		perror("Invalid command");
}

void unset_env (char **argv)
{
	char *name = argv[1];
	
	if (name == NULL)
	{
		perror("unset: not enough arguments");
		return;
	}
	if (unsetenv(name) == -1)
		perror("an error accured");	
}
