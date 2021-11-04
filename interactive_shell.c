#include "shell.h"

/**
 * run_interactive_sh - runs shell in interactive mode
 */
void run_interactive_sh(void)
{
	char *line; /* a pointer to raw cmd input */
	int chars_read;
	char **argv = NULL; /* a pointer to cmd args */
	/* char *arg = NULL; */

	/* read commandline, make line point to it */
	while ((chars_read = prompt(&line)) > 0)
	{
		argv = _strtok(line); /* tokenize the line read */

		if (_strcmp(argv[0], ""))
			continue;

		if (is_command(argv[0]))
		{
			exec_cmd(argv, NULL);
		}

		/* free each block off argv */
		free_argv(argv);
		free(line);
	}

	if (chars_read == -1)
		exit(1);
	exit(0);
}
