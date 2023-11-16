#include "main.h"

/**
 * find_path - finds the fullpath of a file
 * @filename: the name of the file
 * Return: the full path to the file
 */

char *find_path(char *command)
{
	char *path, *path_copy, *token, *fullpath;
	int cmd_len, dir_len;
	/*struct stat buffer;*/
	
	path = getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		cmd_len = _strlen(command);
		token = _strtok(path_copy, ":");
		while (token != NULL)
		{
			dir_len = _strlen(token);
			fullpath = malloc(cmd_len + dir_len + 2);
			_strcpy(fullpath, token);
			_strcat(fullpath, "/");
			_strcat(fullpath, command);
			_strcat(fullpath, "\0");
			if (access(fullpath, F_OK) == 0)
			{
				free(path_copy);
				return (fullpath);
			}
			else
			{
				free(fullpath);
				token = _strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (access(command, F_OK) == 0)
		{
			return(command);
		}
		return(NULL);
	}
	return (NULL);
}
