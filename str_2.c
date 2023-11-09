#include "main.h"

/**
 * _strcpy - copies a string to another string
 * @dest: the destination
 * @src: the string to be copied
 * Return: the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: a copy of the string
 */

char *_strdup(char *str)
{
	char *str_copy;

	if (str == NULL)
		return (NULL);

	str_copy = (char *)malloc((_strlen(str) + 1) * sizeof(char));

	if (str_copy == NULL)
		return (NULL);

	_strcpy(str_copy, str);

	return (str_copy);
}

int _strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (0);
		str++;
	}
	
	return (-1);
}
