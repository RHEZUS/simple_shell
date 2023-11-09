#include "main.h"


/**
 * run_command - runs a command
 * @command: the path to the file
 * @argv: the list of arguments
 */

void run_command(char **argv)
{
	int status = 0, n = 0;

	if (_strcmp(argv[0], "exit") == 0)
	{
		n = _atoi(argv[1]);
		_exit(n);
	}
	else if (_strcmp(argv[0], "env") == 0)
		print_env();
	else if (_strcmp(argv[0], "setenv") == 0)
		set_env(argv);
	else if (_strcmp(argv[0], "unsetenv") == 0)
		unset_env(argv);
	else if (_strcmp(argv[0], "cd") == 0)
		change_dir(argv);
	else
	{
		argv[0] = find_path(argv[0]);
		if (argv[0] == NULL)
		{
			free(argv[0]);
			perror("./shell");
		}
		else
		{
			if (fork() == 0)
			{
				execve(argv[0], argv, environ);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else
				wait(&status);
		}
	}
}
