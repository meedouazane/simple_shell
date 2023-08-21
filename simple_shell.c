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
	int i = 0, j;

	(void)argc;
	buffer = NULL;
	while (1)
	{
		buffer = input();
		if (buffer == NULL)
			continue;
		array = split(buffer, " \t\n");
		if (array == NULL)
		{
			free(buffer);
			continue;
		}
		i = 0;
		while (array[i] != NULL)
		{
			if (_strcmp(array[i], " ") == 0)
			{
				for (j = i; array[j] != NULL; j++)
					array[j] = array[j + 1];
			}
			else
			i++;
		}
		if (main_helper(array, argv[0]) != -1)
		{
			free(buffer);
			continue;
		}
		exec(array, argv[0]);
		continue;
		free_array(array);
		free(buffer);
	}
	return (0);
}

