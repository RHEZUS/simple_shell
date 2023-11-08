#include "main.h"


/**
 * run_command - runs a command
 * @command: the path to the file
 * @argv: the list of arguments
 */

void run_command(char *command, char **argv)
{
	int status = 0, n = 0;

	if (_strcmp(command, "clear") == 0)
		system("clear");
	else if (_strcmp(command, "exit") == 0)
	{
		n = _atoi(argv[1]);
		_exit(n);
	}
	else if (_strcmp(command, "env") == 0)
		print_env();
	else if (_strcmp(command, "setenv") == 0)
		set_env(argv);
	else if (_strcmp(command, "unsetenv") == 0)
		unset_env(argv);
	else if (_strcmp(command, "cd") == 0)
		change_dir(argv);
	else
	{
		command = find_path(command);
		if (command == NULL)
			perror("./shell");
		else
		{
			if (fork() == 0)
			{
				execve(command, argv, NULL);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else
				wait(&status);
		}
	}
}
