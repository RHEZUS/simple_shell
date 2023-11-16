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
 * main - entry point
 * Return: always 0
 */
int main(int ac, char **argv)
{
	char *line = NULL,  *line_copy = NULL, *token;
	size_t len = 0;
	ssize_t read_chars = 0;
	const char *delim = " \n";
	int count_token = 0, i;
	
	(void)ac;
	
	while (1)
	{
		write(0, "$ ", 2);
		read_chars = getline(&line, &len, stdin);
		if (read_chars == -1)
		{
			break;
		}
		handle_comment(line);
		line_copy = malloc(sizeof(char) * read_chars);
		if (line_copy == NULL)
		{
			perror("tsh: memory allocation error");
            		return (-1);
            	}
            	_strcpy(line_copy, line);
		token  = _strtok(line, delim);
		while (token != NULL)
		{
			count_token++;
			token = _strtok(NULL, delim);
		}
		count_token++;
		argv = malloc(sizeof(char *) * count_token);
		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
		    argv[i] = malloc(sizeof(char) * strlen(token));
		    strcpy(argv[i], token);
		    token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		run_command(argv);
		count_token = 0;
	}
	free(line_copy);
    	free(line);
	return (0);
}
