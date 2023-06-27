#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
  *main - entry point
  *buffer: pointer to a character used to store the user input
  *@buffer_size: size of buffer allocated for input
  *@input_len: integer to store length
  *@child_pid: stores child process id
  *@stat: to store exit status or end of child process
  *Return : Always 0
  */
int main(void)
{
	char *buffer = NULL, prompt = '$';
	size_t buffer_size = 0;
	ssize_t input_len;

	while (1);
	{
		write(STDOUT_FILENO, prompt, 2);

		input_len = getline(&buffer, &buffer_size, stdin);
		if (input_len == -1){
			write(STDOUT_FILEO, "\n", 1);
			break;
		}

		buffer[input_len - 1] = '\0';
		/* to remove any newline*/

		free(buffer);
		return (0);
	}
}
