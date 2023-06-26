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
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t read_status;
	const char *delim = " \n";
	char *token = strtok(lineptr, delim);
	int num_tokens = 0;
	int i;

	/* Declaring variables as void */
	(void)argc;
	(void)argv;

	/* Implenting an infinite loop */
	for (;;)
	{
	printf("%s", prompt);
	read_status = getline(&lineptr, &n, stdin);

	/* Verify if the getline fxn failed, hit EOF, or the user pressed CTRL + D.*/
	if (read_status == -1)
	{
		printf("exiting shell....\n");
		return (-1);
	}

	/* Reserve space for the copy of the lineptr */
	lineptr_copy = malloc(sizeof(char) * read_status);
	if (lineptr_copy == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	/*copy from lineptr to lineptr_copy */
	strcpy(lineptr_copy, lineptr);

	/*********** Create an array of words from the string (lineptr) ***********/
	/* perform tokenization and calculations for the total number of tokens. */
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	/* Create space that will hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens);

	/* keep each token safely in the argv array */
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	printf("%s\n", lineptr);


	/* Release allocated memory */
	free(lineptr);
	}

	return (0);
}
