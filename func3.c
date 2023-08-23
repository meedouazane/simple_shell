#include "main.h"
/**
 * _getenv - get variable.
 *@name: the name of variable.
 *Return: the variable that we looking for.
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *key, *value, *result;
	char *env_copy;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy = _strdup(environ[i]);
		if (env_copy == NULL)
			return (NULL);
		key = _strtok(env_copy, "=");
		value = _strtok(NULL, "\n");
		if (key != NULL && value != NULL && _strcmp(key, name) == 0)
		{
			result = _strdup(value);
			free(env_copy);
			return (result);
		}
		free(env_copy);
	}
	return (NULL);
}

/**
 * exec- excute a program.
 * @array: inputed strings.
 * @av: string of arguments.
 * Return: (0) Success (-1) for failure
 */
int exec(char **array, char *av)
{
	pid_t pid;
	char *cmd;
	int status, i = 0;

	cmd = _get_path(*array);
	if (cmd != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			while (array[i] != NULL)
			{
				if (_strcmp(array[i], ";") == 0)
					array[i] = '\0';
				i++;
			}
			if (execve(cmd, array, environ) == -1)
				print_error(array, av, " : Not found");
			free(cmd);
			return (1);
			}
		else
			wait(&status);
	}
	else
	{
		print_error(array, av, " : Not found");
		return (-1);
	}
	free_array(array);
	return (-1);
}
/**
 * _unsetenv - remove a variable
 *@name: variable name.
 *Return: (0) Success (-1) for failure
 */
int _unsetenv(const char *name)
{
	int i = 0;

	if (name == NULL)
		return (-1);

	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			environ[i] = NULL;
			return (0);
		}
		else
	i++;
	}
	perror("This variable doesn't exist");
	return (0);
}
/**
 * _setenv- add a variable.
 * @name: name of variable.
 * @value: the value of variable.
 * @overwrite: 1 for overwrite 0 for not overwrite.
 * Return: (0) Success (-1) for failure
 */
int _setenv(const char *name, char *value, int overwrite)
{
	int i = 0;
	char *new_val;
	int length = 0;

	if (name == NULL || value == NULL)
	{
		_puts("setenv: missing operand");
		return (-1);
	}
	 length = _strlen(name) + _strlen(value) + 2;
	while (environ[i])
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
		if (overwrite == 1)
		{
			new_val = malloc(length);
			_strcpy(new_val, name);
			_strcat(new_val, "=");
			_strcat(new_val, value);
			environ[i] = new_val;
		}
		return (0);
		}
	i++;
	}
			new_val = malloc(length);
			_strcpy(new_val, name);
			_strcat(new_val, "=");
			_strcat(new_val, value);
			environ[i] = new_val;
			environ[i + 1] = NULL;
	return (0);
}

