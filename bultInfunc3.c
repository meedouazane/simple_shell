#include "main.h"
/**
 * _lineputs - prints s string without moving to new line.
 * @str: the string we want to print.
 * Return: Always 0 (Success).
 */
void _lineputs(char *str)
{
	while (*str != 0)
	{
		_putchar(*str);
		str++;
	}
}

