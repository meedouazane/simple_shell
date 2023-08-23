#include "main.h"
/**
 * main - The Main Entry
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char **array;
	char *buffer;
	int i = 0;
	int is_terminal = isatty(0);

	(void)argc;
	buffer = NULL;
	while (1)
	{
		buffer = input(is_terminal);
		if (buffer == NULL)
			continue;
		array = split(buffer, " \n");
		if (array == NULL)
		{
			free(buffer);
			continue;
		}
		if (_strcmp(array[i], " ") == 0)
			continue;
		if (_strcmp(array[0], "#") == 0 || _strncmp(array[0], "#", 1) == 0)
			continue;
		if (main_helper(array, argv[0]) != -1)
		{
			free(buffer);
			continue;
		}
		if (exec(array, argv[0]))
		{
			free(array);
			free(buffer);
			continue;
		}
		free_array(array);
		free(buffer);
	}
	return (0);
}

