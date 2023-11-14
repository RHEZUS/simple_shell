#include "main.h"

/**
 * find_path - finds the fullpath of a file
 * @filename: the name of the file
 * Return: the full path to the file
 */

char *find_path(char *filename)
{
	char *path = _getenv("PATH"), *path_copy = _strdup(path),
		 *dir = _strtok(path_copy, ":"), fullpath[1024] = "";
	unsigned int len = 0;

	if (filename[0] == '/' || filename[0] == '.' || filename[0] == '~')
	{
		if (access(filename, F_OK) == 0)
		{
			free(path_copy);
			return (_strdup(filename));
		}
	}
	else if (path == NULL || filename == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	else
	{
		while (dir != NULL)
		{
			len = _strlen(dir) + _strlen(filename) + 1;
			if (len > sizeof(fullpath))
			{
				free(path_copy);
				return (NULL);
			}
			_strcpy(fullpath, dir);
			_strcat(fullpath, "/");
			_strcat(fullpath, filename);
			if (access(fullpath, F_OK) == 0)
			{
				free(path_copy);
				return (_strdup(fullpath));
			}
			dir = _strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}
