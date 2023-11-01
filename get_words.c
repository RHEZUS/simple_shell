#include "main.h"

int countWords(const char *input)
{
	int wordCount = 0;
	const char *ptr = input;

	while (*ptr != '\0')
	{
		while (*ptr != '\0' && isspace(*ptr)) ptr++;
		if (*ptr != '\0')
		{
			wordCount++;
			while (*ptr != '\0' && !isspace(*ptr)) ptr++;
		}
	}

	return wordCount;
}

void splitString(const char *input, char ***words, int *wordCount)
{
	int wordIndex = 0;
	const char *ptr = input;
	const char *wordStart;
	int wordLength;
	if (input == NULL || words == NULL || wordCount == NULL)
		return;

	*wordCount = countWords(input);
	*words = (char **)malloc(*wordCount * sizeof(char *));

	if (*words == NULL) return; 
	    
	while (*ptr != '\0') {
		while (*ptr != '\0' && isspace(*ptr)) ptr++;
		if (*ptr != '\0')
		{
			wordStart = ptr;

			while (*ptr != '\0' && !isspace(*ptr)) ptr++;

			wordLength = ptr - wordStart;

			(*words)[wordIndex] = (char *)malloc(wordLength + 1);

			if ((*words)[wordIndex] == NULL)
			{
				for (int i = 0; i < wordIndex; i++)
					free((*words)[i]);
				free(*words);
				*words = NULL;
				*wordCount = 0;
				return;
			}
			strncpy((*words)[wordIndex], wordStart, wordLength);
			(*words)[wordIndex][wordLength] = '\0';
			wordIndex++;
		}
	}
}
