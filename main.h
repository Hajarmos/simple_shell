#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *_which(char *cmdname, char **envp);
char *_getenv(const char *name, char **environ);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _atoi(char *s);
char *_strdup(char *str);
char **splitstr(char *buffer);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
