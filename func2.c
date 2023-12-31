#include "main.h"
/**
 * split - splits a string.
 * @buf: the buffer that we'll split.
 * @del: delimiter that we'll use to split.
 * Return: splited strings.
 */
char **split(char *buf, char *del)
{
	char *token;
	char **array;
	int i = 0;

	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		free_array(array);
		return (NULL);
	}
	token = _strtok(buf, del);
	while (token)
	{
		array[i] = token;
		token = _strtok(NULL, del);
		i++;
	}
	array[i] = NULL;
	return (array);
	free_array(array);
}
/**
 * _get_path - get full path of any command.
 * @cmd: command.
 * Return: full path of command.
 */
char *_get_path(char *cmd)
{
	char *path, *tok, *full_path;
	struct stat st;
	size_t len;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	tok = _strtok(path, ":");
	while (tok)
	{
		len = _strlen(tok) + _strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path);
			return (NULL);
		}
		_strcpy(full_path, tok);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		tok = _strtok(NULL, ":");
	}
	if (stat(cmd, &st) == 0)
	{
		free(path);
		return (cmd);
	}
	free(path);
	return (NULL);
}

/**
 * _environ - prints the current environment.
 * Return: Always 0.
 */

void _environ(void)
{
	char **env = environ;

	for (; *env; env++)
	{
		_puts(*env);
	}
}
/**
 * input - get input from shell
 * @interactive: if it 1 continue 0 stop.
 * Return: buffer of strings
 */
char *input(int interactive)
{
	int get = 0;
	int i = 0, j = 0;
	char *buf = NULL;
	size_t n = 10;

	if (interactive)
	write(1, "$ ", 2);
		get = getline(&buf, &n, stdin);
		if (get == -1)
		{
			free(buf);
			exit(0);
		}
		while (buf[0] == '\n')
		{
			if (interactive)
			write(1, "$ ", 2);
			get = getline(&buf, &n, stdin);
		}
		while (buf[i] != '\0')
		{
			if (buf[i] == ' ')
			{
				for (j = i; buf[j] != '\0'; j++)
					buf[j] = buf[j + 1];
			}
			else if (buf[i] == '\0' || buf[i] != ' ')
			{
				break;
			}
			else
				i++;
		}
	return (buf);
}

