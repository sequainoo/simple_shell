#include "shell.h"

/**
 * _getline - reads line from `stdin`
 * @lineptr: a pointer to a line / ptr to char *
 * Return: the number of chars read
 */
int _getline(char **lineptr)
{
	char *buffer;
	static size_t buffsize = 2024;
	size_t chars_read, i = 0;

	buffer = malloc(sizeof(char) * buffsize);
	if (buffer == NULL)
		return (-1);

	chars_read = read(STDIN_FILENO, buffer, buffsize);

	/* if read() returns 0 then is EOF and no err, dont count*/
	if (chars_read == 0)
		return (chars_read);

	/* if read() returns -1 is an error return -1 */
	else if (!chars_read)
	{
		free(buffer);
		return (-1);
	}

	/* remove trailing newline */
	while (i < buffsize)
	{
		if (buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}

	/* if chars_read < buffsize realloc to optimise memory space */
	if (chars_read < buffsize)
	{
		buffer = realloc(buffer, sizeof(char) * chars_read + 1);
		buffer[chars_read] = '\0';
	}

	*lineptr = buffer;

	return (chars_read);
}
