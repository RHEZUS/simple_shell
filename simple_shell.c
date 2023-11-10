#include "main.h"

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

	while (1)
	{
		write(0, "$ ", 2);
		read = _getline(&line, &len, STDIN_FILENO);

		if (read == -1)
			break;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';
		
		i = 0;
		arg = _strtok(line, " \t\n");
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
	free(line);
	return (0);
}
