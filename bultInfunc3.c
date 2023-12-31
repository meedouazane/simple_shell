#include "main.h"
/**
 * _lineputs - prints s string without moving to new line.
 * @str: the string we want to print.
 *
 *
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
/**
 * _atoi- convert string to int.
 * @str: string we want to convert to int
 * Return: return 0 if code succeed else -1
 */
int _atoi(char *str)
{
	int i = 0;

	long int result = 0;
	int sign = 1;

	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return ((int)(result * sign));
}
/**
 * _oputs - prints s string until second slash
 * @str: the string we want to print.
 * Return: Always 0 (Success).
 */
void _oputs(char *str)
{
	int slashCount = 0;

	while (*str != 0)
	{
		if (*str == '/')
		{
			slashCount++;
			if (slashCount == 2)
			break;
		}
			_putchar(*str);
		str++;
	}
	_putchar('\n');
}
