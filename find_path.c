#include "main.h"

/***/


char *find_path(char *filename)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char *full_path = NULL;
	int len = 0;

	if (access(filename, F_OK | X_OK) == 0)
		return (filename);
	if (path == NULL || filename == NULL || strcmp(filename, "") == 1)
		return (NULL);
	while (dir != NULL)
	{
		len = sizeof(dir) + sizeof(filename) + 2;
		full_path = realloc(full_path, len);
		snprintf(full_path, len, "%s/%s", dir, filename);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path_copy);
			return(strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
