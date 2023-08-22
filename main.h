#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
extern char **environ;
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
void _cexit(char *array);
char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_get_path(char *cmd);
char **split(char *buf, char *del);
void _environ(void);
void changeDir_helper(char *oldpwd, char *currentpwd);
void changeDir_helper2(char **array, char *rep, int array_size);
char *input(void);
int _setenv(const char *name, char *value, int overwrite);
int _unsetenv(const char *name);
int exec(char **array, char *av);
int changeDir(char **array, char *av);
int main_helper(char **array, char *av);
int _putchar(char c);
char *_strtok(char *str, const char *delim);
void _puts(char *str);
char *_strchr(const char *s, char c);
char *_strdup(const char *str);
void free_array(char **array);
void _lineputs(char *str);
void print_error(char **array, char *av, char *message);
int _atoi(char *s);
#endif

