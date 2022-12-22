#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

char **tokenization(char *str, char *delim);
int execution(char **tokens, char **env);
char *path(char **env);
char *add_path(char **tokens, char **path_tok);
int isexit(char **tokens);
void sigfunc(int signal);
char **envcopy(char **env);

/* Auxiliar Functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *comparing, char *compare);
void free_array(char **tokens);
int _strncmp(char *comparing, char *compare, size_t n);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
#endif
