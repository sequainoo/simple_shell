#include "shell.h"

/**
 * _strcmp - compares 2 strings for equivalence
 * @str1: first string
 * @str2: second string
 * Return: int 1 if they are equivalent and zero otherwise
 */
int _strcmp(char *str1, char *str2)
{
    int i = 0;
    int len1 = _strlen(str1);
    int len2 = _strlen(str2);

    if (len1 != len2)
        return (0);

    while (i < len1)
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    return (1);
}
