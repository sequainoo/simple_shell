#include "shell.h"

/**
 * main - a simple unix shell program
 * @argc: the count of the number of arguments
 * @av: the argument values passed to the program
 * Return: 0 upon successful termination
 */
int main(int argc, char **av)
{
	/* if shell is run with commandline arg: non interactive mode */
	if (argc > 1)
	{
		exec_cmd_non_interactive(argc, av);
	}

	/* then run interactive shell */
	run_interactive_sh(av);
	return (0);
}
