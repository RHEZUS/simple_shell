#include "main.h"

/**
 * change_dir - changes the current directory
 *
 * @argv: a list of argument
 */

void change_dir(char **argv)
{
	const char *dir = argv[1];

	if (dir == NULL || strcmp(dir, "~") == 0)
		dir = _getenv("HOME");
	else if (strcmp(dir, "-") == 0)
		dir = _getenv("OLDPWD");

	if (chdir(dir) == -1)
		perror("chdir");
	else
		setenv("PWD", dir, 1);
}

/**
 * print_env - prints the current environment
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * _getenv - returns a specific environment variable
 * @var_name: the name of the variable
 * Return: a pointer to the environment variable
 */

char *_getenv(char *var_name)
{
	size_t var_len = _strlen(var_name);
	char **env;

	if (var_name == NULL || environ == NULL)
		return (NULL);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(var_name, *env, var_len) == 0 &&
			(*env)[var_len] == '=')
			return (&(*env)[var_len + 1]);
	}

	return (NULL);
}

/**
 * set_env - creates or updates an environment variable
 * @argv: a list of arguments
 */

void set_env(char **argv)
{
	char *name = argv[1];
	char *value = argv[2] == NULL ? " " : argv[2];

	if (setenv(name, value, 1) == -1)
		perror("Invalid command");
}

/**
 * unset_env - unset an environment variable
 * * @argv: a list of arguments
 */

void unset_env(char **argv)
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
