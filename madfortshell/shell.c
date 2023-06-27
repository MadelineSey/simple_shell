#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
  *main - entry point
  *@argc: arg count
  *@argv: arg vector
  *@env: env
  *buffer: pointer to a character used to store the user input
  *buffer_size: size of buffer allocated for input
  *input_len: integer to store length
  *child_pid: stores child process id
  *stat: to store exit status or end of child process
  *Return: Always 0
  */
int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL, *prompt = "madfort$";
	size_t buffer_size = 0;
	ssize_t input_len;

	while (1)
	{
		/*print prompt ; "madfort$" on terminal"*/
		write(STDOUT_FILENO, "madfort$", 2);

		input_len = getline(&buffer, &buffer_size, stdin);
		if (input_len == -1)
		{
			perror("Error from (getline)");
			free(buffer);/*if getline fail*/
			exit(EXIT_FAILURE);
		}
		if (buffer[input_len - 1] == '\n')
			buffer[input_len - 1] = '\0';
		/* to remove any newline*/
		free(buffer);
		return (0);
	}
}
