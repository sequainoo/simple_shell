#include "shell.h"

/**
 * exec_cmd - executes a given program with its argv in a child process
 * @argv: the command to execute, a list of char *
 * @envp: the programming environment variables
 */
void exec_cmd(char **argv, char **envp)
{
	pid_t cpid; /* child pid */
	int status;

	/* if command is not a binary or program */
	if (_strcmp(argv[0], "exit"))
		exit(EXIT_SUCCESS);

	if (_strcmp(argv[0], "env") || _strcmp(argv[0], "printenv"))
		_printenv();

	/* if command is a program */
	cpid = fork();

	if (cpid == -1)
	{
		perror(argv[0]);
		exit(1);
	}
	else if (cpid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			set_bin_path(argv);

			if (execve(argv[0], argv, envp) == -1)
			{
				perror(argv[0]);
				exit(1);
			}
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * exec_cmd_non_interactive - executes cmd line args in non interactive mode
 * @argc: number of args *
 * @av: the command to execute, a list of char *
 * @envp: the programming environment variables
 */
void exec_cmd_non_interactive(int argc, char **av, char **envp)
{
	pid_t cpid;
	int status, i;
	char **argv;

	argv = malloc(sizeof(char *) * argc);

	i = 0;
	while (av[i])
	{
		argv[i] = av[i + 1];
		i++;
	}

	cpid = fork();
	if (cpid == -1)
	{
		perror(argv[0]);
		exit(1);
	}
	else if (cpid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
