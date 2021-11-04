#include "shell.h"

/**
 * prompt - sends prompt signal to terminal and readline
 * @lineptr: a pointer to a line / ptr to char *
 * Return: the number of chars read
 * Description: uses _getline to readline from `stdin`
 */
int prompt(char **lineptr)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (_getline(lineptr));
}
