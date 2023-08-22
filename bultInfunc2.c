#include "main.h"
/**
 * _strchr - locates a char in string
 * @s: string
 * @c: char
 * Return: Returns a pointer to the first occurrence of the char c in s.
 */
​
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints s string.
 * @str: the string we want to print.
 * Return: Always 0 (Success).
 */
void _puts(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
/**
 * _strdup- return a pointer to a new string which is a duplicate.
 * @str: input string
 * Return: duplicated string.
 */
​
char *_strdup(const char *str)
{
	char *p;
	int i = 0;
	int length = 0;
​
	if (str == NULL)
		return (NULL);
​
	length = _strlen(str);
​
	p = (char *) malloc(length + 1 * sizeof(char));
​
	if (p == NULL)
		return (p);
​
​
	while (i < length)
	{
		*(p + i) = *(str + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
/**
 * _strncmp - compare first n of char.
 * @s1: destination string
 * @s2: source string
 * @n: char number.
 * Return: Always 0 (Success)
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int re = 0;
​
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
		{
			re = (int)(*s1) - (int)(*s2);
			break;
		}
		s1++;
		s2++;
		n--;
	}
	if (n > 0 && *s1)
		re = (int)(*s1);
	else if (n > 0 && *s2)
		re = -(int)(*s2);
​
	return (re);
}

