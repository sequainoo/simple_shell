#include "shell.h"

/**
 * _strlen - return the  length of a string
 * @str: the string in question
 * Return: the length as an int
 */
int _strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return (0);

    while (*str++ != '\0')
        len++;
    
    return (len);
}