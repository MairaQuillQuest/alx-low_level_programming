#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * helper - helps function
 * @word: wordcount
 * @len: length
 * @str: string to go through
 * @s: array you are assigning
 * Return: char value
 */
char **helper(int word, int len, char *str, char **s)
{
	int i, k, j;

	j = 0;
	for (i = 0; i < word; i++)
	{
		k = 0;
		while (str[j] == ' ')
			j++;
		while (j < len && str[j] != ' ')
		{
			s[i][k] = str[j];
			k++;
			j++;
		}
		s[i][k] = '\0';
	}
	s[word] = NULL;
	return (s);
}

/**
 * strtow - string to words
 * @str: string to check
 * Return: return char value
 */
char **strtow(char *str)
{
	int len, i, j, size, k, word;
	char **s;

	if (str == NULL || *str == '\0')
		return (NULL);
	len = 0;
	word = 0;
	while (str[len] != '\0')
	{
		while (str[len] == ' ')
			len++;
		if (str[len] != '\0')
			word++;
		while (str[len] != ' ' && str[len] != '\0')
			len++;
	}
	s = (char **)malloc(sizeof(char *) * (word + 1));
	if (s == NULL)
		return (NULL);
	j = 0;
	for (i = 0; i < word; i++)
	{
		size = 0;
		while (str[j] == ' ')
			j++;
		while (j < len && str[j] != ' ')
		{
			size++;
			j++;
		}
		s[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (s[i] == NULL)
		{
			for (k = i - 1; k >= 0; k--)
				free(s[k]);
			free(s);
			return (NULL);
		}
	}
	return (helper(word, len, str, s));
}
