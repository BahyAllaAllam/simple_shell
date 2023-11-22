#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **env);
ssize_t get_line(char **buff, size_t *n, FILE *stream);
char *str_tok(char *str, const char *delim);
void free_arrays(char **array);
int excute_command(char **args, char **env);
int find_commands(char **args, char **env);
void del_comment(char *line);
char *read_line(void);
char **split_line(char *line);
char **split_paths(char *paths);
char *check_path(char **args, char **paths);
void loop(char **env);

#define BUFFSIZE 1024
#define DELIMITRS " \n\t\r\a"

#endif
