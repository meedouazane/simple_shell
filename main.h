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
#include <errno.h>
extern char **environ;
void _oputs(char *str);
/* bultInfunc1.c */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);

/* bultInfunc2.c */
char *_strchr(const char *s, char c);
int _putchar(char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
void _puts(char *str);

/* bultInfunc3.c */

void _lineputs(char *str);
int _atoi(char *s);

void _cexit(char *array);
char *_getenv(const char *name);
char *_get_path(char *cmd);
char **split(char *buf, char *del);
void _environ(void);
void changeDir_helper(char *oldpwd, char *currentpwd);
void changeDir_helper2(char **array, char *rep, int array_size);
char *input(int interactive);
int _setenv(const char *name, char *value, int overwrite);
int _unsetenv(const char *name);
int exec(char **array, char *av);
int changeDir(char **array, char *av);
int main_helper(char **array, char *av);
char *_strtok(char *str, const char *delim);
void free_array(char **array);
void print_error(char **array, char *av, char *message);

#endif

