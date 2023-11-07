#include "main.h"

int string_to_int(char *str)
{
	int i = 0, n = 0;
	
	if (str == NULL)
		return (0);
		
	while (str[i] != '\0')
	{
		if (str[i] > '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (n);
}

void updatePWD (const char *newDir)
{
	setenv("PWD", newDir, 1);
}

void change_dir(char **argv)
{
	const char *dir = argv[1];
	if (dir == NULL || strcmp(dir, "~") == 0)
		dir = getenv ("HOME");
	else if (strcmp(dir, "-") == 0)
		dir = getenv("OLDPWD");
	
	if (chdir(dir) == -1)
		perror("chdir");
	else
		updatePWD(dir);
}

/***/

void run_command(char *command, char **argv)
{
	int status = 0, n = 0;
	if (strcmp(command, "clear") == 0)
		system("clear");
	else if (strcmp(command, "exit") == 0)
	{
		n = string_to_int(argv[1]);
		exit(n);
	}
	else if (strcmp(command, "env") == 0)
		print_env();
	else if (strcmp(command, "setenv") == 0)
		set_env(argv);
	else if (strcmp(command, "unsetenv") == 0)
		unset_env(argv);
	else if (strcmp(command, "cd") == 0)
		change_dir(argv);
	else
	{
		command = find_path(command);
		
		if (command == NULL)
			perror("Command not found");
		else
		{
			if (fork() == 0)
			{
				execve(command, argv, NULL);
				perror("");
				exit(EXIT_FAILURE);
			}
			else
				wait(&status);
		}
	}
}
