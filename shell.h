#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_strtok(char *str, const char *delim);
char *_strdup(const char *str);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
void free_array(char **array);

char *get_line(void);

char **tokenize_input(char *input_line);

int execute_cmd(char **command_tokens, char **argv);

#endif
