#include "shell.h"

/**
 * set_bin_path - takes the first arg of a command and set its
 * full binary path
 * @argv: the command arguments from which the command name is
 * Description: if argv comes as `ls -l` set path of `ls` to `/bin/ls`
 */
void set_bin_path(char **argv)
{
    char *buffer, *cmd_name;
    int buff_len, cmd_len, bin_path_len, i, j;
    char bin_path[] = {'/', 'b', 'i', 'n', '/', '\0'};

    cmd_name = *argv;
    bin_path_len = _strlen(bin_path);
    cmd_len = _strlen(cmd_name);
    buff_len = bin_path_len + cmd_len;

    /* alloc mem for the path to bin and cmd name string */
    buffer = malloc(sizeof(char) * buff_len + 1);
    if (buffer == NULL)
        exit(1);

    /* fill buffer with path to bin */
    i = 0;
    while (i < bin_path_len)
    {
        buffer[i] = bin_path[i];
        ++i;
    }

    /* continue filling buffer with cmd name string */
    j = 0;
    while (i < buff_len)
    {
        buffer[i] = *(cmd_name + j);
        ++i;
        ++j;
    }
    buffer[i] = '\0';

    /* replace argv[0] with the new path to the cmd bin */
    argv[0] = buffer;
    /* free(cmd_name); */
}
