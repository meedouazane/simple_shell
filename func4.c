#include "main.h"
/**
 * changeDir_helper2- Changes the current directory.
 * @array: inputed strings.
 * @array_size: size of the array.
 * @rep: full path.
 * Return: alaways 0
 */
void changeDir_helper2(char **array, char *rep, int array_size)
{
	int i = 2;

	while (i < array_size)
	{
		_strcat(rep, "/");
		_strcat(rep, array[i]);
		i++;
	}
}
/**
 * free_array - free memory.
 * @array: inputed strings.
 * Return : Always 0.
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
/**
 *print_error- print errors.
 *@array: inputed strings.
 *@av: string of arguments.
 *@message: error that we'll be printed.
 *Return: always 0.
 */
void print_error(char **array, char *av, char *message)
{
	static int i = 1;

	_lineputs(av);
	_lineputs(": ");
	if (i <= 9)
		_putchar('0' + i);
	else
	{
		_putchar('0' + i / 10);
		_putchar('0' + i % 10);
	}
	_lineputs(": ");
	_lineputs(array[0]);
	_lineputs(": ");
	_lineputs(message);
	_oputs(array[1]);
	i++;
}

