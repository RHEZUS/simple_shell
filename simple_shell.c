#include "main.h"

/***/


int main(void)
{

	char *envp = {NULL};
	size_t len = 0;
	ssize_t read = 0;
	int status = 0;
	char *command = NULL;
	char **words = NULL;
	int wordCount = 0;

	while (1)
	{
		printf("simple_shell$ ");

		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin) == 0)
				break;
			else
			{
				perror("Error reading input");
				exit (EXIT_FAILURE);
			}
		}
		
		if (read > 0 && command[read - 1] == '\n')
			command[read - 1] = '\0';

		if (fork() == 0)
		{	
			(char *const)words;
			execve(command, splitString(command, &words, &wordCount), NULL);
			perror("simple_shell ");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
