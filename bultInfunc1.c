#include "main.h"


/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int i, j = 0;

	while (dest[j] != 0)
	{
		j++;
	}
	for (i = 0; src[i] != 0; i++)
	{
		dest[j + i] = src[i];
	}
	dest[j + i] = '\0';

		return (dest);
}
/**
 * _strcpy - copy the string from file to another file
 * @dest: destination
 * @src: the string that we want to copy
 *
 * Return: char  @dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;
	int length = 0;

	for (i = 0; src[i] != 0; i++)
		length++;

	for (i = 0; i <= length; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strcmp - compare two strings
 * @s1: destination string
 * @s2: source string
 * Return: Always 0 (Success)
 */
int _strcmp(const char *s1, const char *s2)
{
	int n = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
		n = ((int)*s1 - 48) - ((int)*s2 - 48);
		break;
		}
		s1++;
		s2++;
	}

	return (n);
}
/**
 * _strlen - return length of a string.
 * @s: the string.
 * Return: len length of string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != 0)
	{
	len++;
	s++;
	}

	return (len);
}

