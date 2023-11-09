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
		read = getline(&line, &len, stdin);

		if (read == -1)
			break;
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		
		i = 0;
		arg = strtok(line, " ");
		
		/*printf("first token %s\n", arg);*/
		while (arg != NULL)
		{
			argv[i++] = arg;
			arg = strtok(NULL, " ");
			/*printf("%dth token %s\n", i, arg);*/
		}
		

		argv[i] = NULL;
		/*
		for (i = 0; argv[i] != NULL; i++)
			printf("%s\n", argv[i]);*/
		run_command(argv);
	}

	return (0);
}
