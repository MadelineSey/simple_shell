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
	char *buffer = NULL, *prompt = "madfort$", *error_mesg = "none";
	size_t buffer_size = 0;
	ssize_t input_len;
	pid_t cpid;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;

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

		if (token == NULL){
			continue;
		}

		/* argument for execve*/

		args[0] = token;
		args[1] = NULL;

		cpid = fork();
		if (cpid == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (cpid == 0)
			_execute(buffer, &statbuff, env);
/* Parent process should wait*/
		if (waitpid(cpid,&wstat, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}
	}
		free(buffer);
		return (0);
	}
}
