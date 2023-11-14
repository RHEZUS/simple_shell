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

/**
 * _strchr - search a character in in a string
 * @str:  the string
 * @c: the char to find
 * Return: the first occurrence of the char in the string
 */
char *_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}

	if (c == '\0')
	{
		/* Return pointer to null terminator for '\0' */
		return ((char *)str);
	}

	return (NULL);
}

/**
 * delete_char - delete a char in a string
 * @str: the string
 * @ch: the char to delete
 * Return: the new string
 */
char *delete_char(char *str, char ch)
{
	int length = _strlen(str);
	int i, j;

	for (i = 0, j = 0; i < length; i++)
	{
		if (str[i] != ch)
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0'; /* Null-terminate the string after deletion*/
	return (str);
}

/**
 * int_to_string - cast an integer to string
 * @num: the number to cast
 * Return: a string
 */
char *int_to_string(unsigned long int num)
{
	int digits = 1;
	unsigned long int temp = num;
	char *str;

	while (temp /= 10)
	{
		digits++;
	}

	str = (char *)malloc((digits + 1) * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	str[digits] = '\0';

	while (num != 0)
	{
		str[--digits] = (num % 10) + '0';
		num /= 10;
	}

	return (str);
}
