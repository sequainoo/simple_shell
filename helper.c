#include "shell.h"

/**
 * free_argv - frees any buffer that stores addresses
 * @argv: a pointer to pointer to char
 */
void free_argv(char **argv)
{
	char *arg = NULL;
	int i = 0;

	/* free each block off argv */
	i = 0;
	while ((arg = *(argv + i)) != NULL)
	{
		free(arg);
		i++;
	}
	i = 0;
	free(argv);
}

/**
 * len_arr_of_ptrs - determines the length of array of pointers
 * @arr: the null terminated array of pointers
 * Return: the len of the array or pointer as an int
 */
unsigned int len_arr_of_ptrs(char **arr)
{
	unsigned int count = 0;

	while (*arr++)
	{
		count++;
	}

	return (count);
}
