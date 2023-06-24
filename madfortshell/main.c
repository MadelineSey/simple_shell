#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: counts the total number of command line arguments
 * @argv: the array holding the command line arguments
 * getline - a function to read a complete line of text from the standard input
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	char *prompt = "(Madfortshell) $ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t read_status;

	/* Declaring variables as void */
	(void)argc;
	(void)argv;

	/* Implenting an infinite loop */
	for (;;)
	{
	printf("%s", read_status);
	read_status = getline(&lineptr, &n, stdin);

	/* Verify if the getline fxn failed, hit EOF, or the user pressed CTRL + D.*/
	if (read_status == -1)
	{
		printf("exiting shell....\n");
		return (-1);
	}

	printf("Read status: %zd\n", read_status);
	printf("Input Line: %s\n", lineptr);

	/* Release allocated memory */
	free(lineptr);
	}

	return (0);
}
