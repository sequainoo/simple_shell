#include "shell.h"

/**
 * is_command - checks if a given command does exists
 * @cmd: a string of the command to check
 * Return: 1 if true and 0 if false
 */
unsigned int is_command(char *cmd)
{
	struct stat st;
	char *cmds[] = {"exit", "env", "cd", "printenv", NULL};
	int len_cmds = len_arr_of_ptrs(cmds);
	int i = 0, j = 0;
	int cmd_len = _strlen(cmd);
	char bin_path[] = "/bin/";
	size_t len_buff = _strlen(bin_path) + cmd_len + 1;
	char *path_buff = _malloc_char(len_buff);

	while (i < len_cmds)
	{
		if (_strcmp(cmd, cmds[i]))
			return (1);
		i++;
	}
	if (stat(cmd, &st) == 0)
		return (1);

	i = 0;

	while (i < _strlen(bin_path))
	{
		path_buff[i] = bin_path[i];
		i++;
	}
	while (j < cmd_len)
	{
		path_buff[i] = cmd[j];
		j++;
		i++;
	}
	path_buff[i] = '\0';

	if (stat(path_buff, &st) == 0)
		return (1);

	fprintf(stderr, "%s: command not found\n", cmd);
	return (0);
}
