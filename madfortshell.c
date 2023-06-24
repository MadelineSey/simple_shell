#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "madfortshell.h"

/**
  *main - entry point
  *execute_shell: task
  *Return: 0
  */
int execute_shell(void)
{
	char *full_command = NULL, *copy_command = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	char *token;
	const char *delim = " \n";
	char **argv;
	int i = 0;
	int num_tokens = 0;

	printf("$ ");
	nchars_read = getline(&full_command, &n, stdin);
	copy_command = malloc(sizeof(char) * nchars_read);
	if (copy_command == NULL)
	{
		perror("tsh: memory allocation error");
		return;
	}
	strcpy(copy_command, full_command);
	if (nchars_read == -1)
	{
		printf("Exiting shell....\n");
		return;
	}
	else
	{
		token = strtok(full_command, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(copy_command, delim);

		for (; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		free(argv);
		free(full_command);
		free(copy_command);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("simple_shell$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		command[strcspn(command, "n")] = 0; /*remove trailing newline*/
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
/*child process*/
			if (execlp(command, command, (char *)NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		} else
		{
/*parent process*/
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	return (0);
	}
}
