#include "main.h"

/**
 * execmd - a function that executes the execve command.
 *
 * @argv: An array of strings denoting the command and its arguments.
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		/* Take the command */
		command = argv[0];

		/* Run the command using execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
