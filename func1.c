#include "main.h"
/**
 * changeDir- Changes the current directory.
 * @array: inputed strings.
 * @av: string of arguments.
 *
 * Return: if succeed return 0 else (-1) for failure
 */
int changeDir(char **array, char *av)
{
	char pb[1024];
	char *p, *OLD, *home, *rep, *s;
	int array_size = 0;

	array_size = sizeof(*array) / sizeof(array[0]);
	s = _getenv("PWD");
	home = _getenv("HOME");
	OLD = _getenv("OLDPWD");
	if (array[1] != NULL)
	{
		p = getcwd(pb, sizeof(pb));
		_setenv("OLDPWD", p, 1);
		if (_strcmp(array[1], "-") == 0)
		{
			changeDir_helper(OLD, s);
			return (0);
		}
		rep = malloc(_strlen(array[1]) + 1);
		_strcpy(rep, array[1]);
		if (array[2] != NULL)
		{
			changeDir_helper2(array, rep, array_size);
			return (0);
		}
		if (chdir(rep) == -1)
		{
			print_error(array, av, "can't cd to ");
			return (-1);
		}
		p = getcwd(pb, sizeof(pb));
		_setenv("PWD", p, 1);
		free(rep);
		}
	else
		chdir(home);
	free(home);
	free(OLD);
	free(s);
	return (0);
}
/**
 * changeDir_helper- Changes the current directory.
 * @oldpwd: OLDPWD variable.
 * @currentpwd: PWD variable.
 * Return: alaways 0
 */
void changeDir_helper(char *oldpwd, char *currentpwd)
{
	if (oldpwd != NULL)
	{
		chdir(oldpwd);
		_puts(oldpwd);
	}
	else
	{
		chdir(currentpwd);
		_puts(currentpwd);
	}
}
/**
 * main_helper - part of main function
 * @array : inputed strings.
 * @av: string of arguments.
 * Return: (0) Success (-1) for failure.
 */
int main_helper(char **array, char *av)
{
	int i = 0;

	while (array[i] != NULL)
	{
		if (_strcmp(array[i], "#") == 0 || _strncmp(array[i], "#", 1) == 0)
			array[i] = '\0';
	i++;
	}
	if (_strcmp(array[0], "env") == 0)
	{
		_environ();
		free(array);
		return (0);
	}
	if (_strcmp(array[0], "setenv") == 0)
	{
		_setenv(array[1], array[2], 1);
		free(array);
		return (0);
	}
	if (_strcmp(array[0], "unsetenv") == 0)
	{
		if (_unsetenv(array[1]) != 0)
			perror("unable unset variable");
		return (0);
	}
	if (_strcmp(array[0], "cd") == 0)
	{
		changeDir(array, av);
		free(array);
		return (0);
	}
	if (_strcmp(array[0], "exit") == 0)
	{
		free_array(array);
		exit(0);
	}
	return (-1);
}
/**
 * _strtok - breaks the given string into a series of tokens.
 * @str: string that we'll break.
 * @delim: delimeter.
 * Return: breaked strings.
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *beg;

	if (str != NULL)
		token = str;
	if (token == NULL || *token == '\0')
		return (NULL);
	beg = token;
	while (*token != '\0' && _strchr(delim, *token) == NULL)
		token++;

	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}
	return (beg);
}
/**
 *_cexit - exit with status.
 *@array: inputed strings.
 *Return: Always 0
 */
void _cexit(char *array)
{
	int status;

	status = _atoi(array);
	exit(status);
	free(array);
}
