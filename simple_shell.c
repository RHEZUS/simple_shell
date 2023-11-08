#include "main.h"

/**
 * main - entry point
 * Return: always 0
 */


int main(void)
{
	char *line = NULL;
	char *arg = NULL;
	char *argv[32];
	size_t len = 0;
	int i = 1;
	ssize_t read = 0;
	char *command = NULL;

	while (1)
	{
		write(0, "$ ", 2);
		read = getline(&line, &len, stdin);

		if (read == -1)
			break;
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
			command = strtok(line, " ");
			argv[0] = command;
			i = 1;
			while ((arg = strtok(NULL, " ")) != NULL)
				argv[i++] = arg;

			argv[i] = NULL;
		}
		run_command(command, argv);
	}

	free(line);
	return (0);
}
