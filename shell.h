#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/* helpers */
void set_bin_path(char **cmd);
int count_tokens(char *str);
char **malloc_tokens(size_t size);
int set_bounds(char **current_lowerbound, char **current_upperbound);
/* void parse_token(char const *const str, char **tokens, int n_tokens); */
void free_argv(char **argv);
unsigned int is_command(char *cmd);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
unsigned int len_arr_of_ptrs(char **arr);

/* utils */
char **_strtok(char *str);
int _getline(char **lineptr);
void exec_cmd(char **argv, char **envp);
void exec_cmd_non_interactive(int argc, char **av, char **envp);
int prompt(char **lineptr);
void run_interactive_sh(void);
void _printenv();

#endif
