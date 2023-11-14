#include "main.h"

/**
 * _atoi - converts a chracter string to an integer
 * @str: the string argument
 * Return: the converted integer value
 */

int _atoi(char *str)
{
	int i = 0, n = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] > '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (n);
}

/**
 * _strlen - returns the length of a string.
 * @str: pointer to string.
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

/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: value less than 0 means s1 is less than s2
 */

int _strcmp(char *str1, char *str2)
{
	int len;

	for (len = 0; str1[len] == str2[len] && str1[len]; len++)
		;

	if (str1[len] > str2[len])
		return (1);
	if (str1[len] < str2[len])
		return (-1);
	return (0);
}

/**
 * _strncmp - compares two strings according to a specified number of byte
 * @str1: the first string
 * @str2: the second string
 * @n: the maximum number of byte to compare
 * Return: 0 if the strings are equal or str1 - str2
 */

int _strncmp(char *str1, char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*str1 - *str2);
}

/**
 * _strcat - concatenates two strings
 * @dest: the frist string to which the second will be added
 * @src: the string to add
 * Return: the concatenated string
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0, len = 0;

	while (dest[len] != '\0')
		len++;

	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];

	dest[len + i] = '\0';

	return (dest);
}
