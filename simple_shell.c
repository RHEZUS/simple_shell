#include "main.h"

/**
 * handle_comment - Handle comment in command
 * @line: line of code (set of commands)
 */
void handle_comment(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#' && (line[i - 1] == ' ' || line[i + 1] == ' '))
		{
			line[i] = '\0';
			break;
		}
	}
}

/**
 * execute_multiple_commands - execute multiple command
 * @line: line of code  (set of commands)
 */
void execute_multiple_commands(char *line)
{
	char *token;
	char *delimiters = "&&||;";
	char *commands[10];
	int index = 0;
	int i;

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		commands[index++] = token;
		token = strtok(NULL, delimiters);
	}

	i = 0;

	while (i < index)
	{
		/*printf("Command: %s\n", commands[i]);*/
		execute_single_command(commands[i]);
		i++;
	}
}

/**
 * execute_single_command - execute a single command
 * @command: the command to execute
 */
void execute_single_command(char *command)
{
	char *argv[32];
	char *arg = NULL;

	int i = 0;
	
	arg = _strtok(command, " \t\n");
	while (arg != NULL)
	{
		argv[i++] = arg;
		arg = _strtok(NULL, " \t\n");
	}

	argv[i] = NULL;
	i = 1;

	while (argv[i] != NULL)
	{

		argv[i] = handle_arguments(argv[i]);
		if (argv[i] == NULL && argv[i + 1] != NULL)
		{
			argv[i] = argv[i + 1];
			argv[i + 1] = NULL;
		}
		i++;
	}
	run_command(argv);
}

/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	char *argv[32];
	char *arg = NULL;
	size_t len = 0;
	int i;
	ssize_t read = 0;

	(void)argv;
	(void)arg;
	(void)i;
	while (1)
	{
		write(0, "$ ", 2);
		read = getline(&line, &len, stdin);

		if (read == -1)
			break;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Handle comments*/
		handle_comment(line);

		i = 0;

		execute_multiple_commands(line);
	}
	free(line);
	return (0);
}
