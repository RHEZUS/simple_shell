#include "main.h"


/**
 * str_length - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */
int _strlen(char *str)
{
	int len = 0;
	
	if (str == NULL)
		return (0);
		
	while (str[len++] != '\0')
	{
	}
	return (--len);
}


/***/

int _strcmp(char *str1, char *str2)
{
    int i = 0;
    
    if (str1 == NULL && str2 == NULL)
		return (0);

	if (str1 == NULL || str2 == NULL)
		return (1);
    
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}


