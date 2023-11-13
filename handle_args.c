#include "main.h"


char *handle_arguments(char *arg)
{
	char *str = arg;
	int status;
	pid_t pid = getpid();
        
        if (arg == NULL)
            return (NULL);
	if (_strchr(arg, '"') != NULL)
	{
		/*printf("thing found\n");*/
		str = delete_char(arg, '"');
	}
	
	if (_strcmp(arg, "$?")  == 0)
	{
		return (WIFEXITED(status) ? "1" : "0");
	}
	else if (_strcmp(arg, "$$") == 0)
	{
		str = int_to_string(pid);
	}
	else if (arg[0] == '$')
	{
		/*printf("a $ thing found\n");*/
		arg = delete_char(arg, '$');
		str = _getenv(arg);
		
		/*printf("here it is: %s \n", str);*/
	}
	else if (strchr(arg, '$'))
	{
		str = _strtok(arg, "$");
		_strcat(str, _getenv(_strtok(NULL, "$")));
	}
	/*printf("nothing found\n");*/
	return (str);
}




