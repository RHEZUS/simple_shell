#include "main.h"

/**
 * _strtok - split a string
 * @str: the string to split
 * @delim: the delimiter
 * Return: a token / word in the string
 */
char *_strtok(char *str, const char *delim)
{
	/* Keeps track of the current position in the string */
	static char *p;
	char *token_start;

	p = NULL;

	if (str != NULL)
		p = str;
	else if (p == NULL || *p == '\0')
		return (NULL);

	token_start = p;

	/* Find the start of the token */
	while (*p != '\0' && _strchr(delim, *p) != NULL)
		++p;

	/* No more tokens */
	if (*p == '\0')
		return (NULL);

	token_start = p;

	/* Find the end of the token */
	while (*p != '\0' && _strchr(delim, *p) == NULL)
		++p;

	if (*p != '\0')
	{
		/* Null-terminate the token */
		*p = '\0';
		++p;
	}

	return (token_start);
}

/**
 * _getline - reads  an entire line from stream
 * @lineptr: the address of the buffer containing the text
 * @n: size of buffer
 * @fd: ss
 * Return: the number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t bytes_read = 0, new_size;
	ssize_t position = 0, result;
	int next_char;
	char *temp;

	if (!lineptr || !n || fd < 0)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = (char *)malloc(*n * sizeof(char));
		if (!*lineptr)
			return (-1);
	}
	while (next_char != '\n')
	{
		result = read(fd, &next_char, 1);
		if (result < 0)
			return (-1);
		else if (result == 0)
		{
			if (bytes_read == 0)
				return (-1); /* Return -1 if no characters read */
			break;
		}
		if (bytes_read >= *n - 1)
		{
			new_size = *n * 2;
			temp = _realloc(*lineptr, bytes_read, new_size);
			if (!temp)
				return (-1);
			*lineptr = temp;
			*n = new_size;
		}
		(*lineptr)[position] = (char)next_char;
		position++;
		bytes_read++;
		if (next_char == '\n')
			break;
	}
	(*lineptr)[position] = '\0'; /* Null-terminate the string */
	return (bytes_read);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 * Return: the pointer to the new memory or null
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptrArr;
	unsigned int i, n = new_size;
	char *old_ptr = ptr;

	if (ptr == NULL)
	{
		ptrArr = malloc(new_size);
		return (ptrArr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);

	ptrArr = malloc(new_size);
	if (ptrArr == NULL)
		return (NULL);

	if (new_size > old_size)
		n = old_size;
	for (i = 0; i < n; i++)
		ptrArr[i] = old_ptr[i];
	free(ptr);
	return (ptrArr);
}
