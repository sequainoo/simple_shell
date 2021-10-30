#include "shell.h"

/**
 * _printenv - prints the environment variables to stdout stream
 */
void _printenv()
{
    extern char **environ;
    int i = 0;

    while (*(environ + i))
        printf("%s\n", environ[i++]);
}