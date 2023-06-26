#include "main.h"

/**
 * get_location - a fxn to find the command's location in the system's path
 *
 * @command: The command for retrieving the location
 * Return: The complete file path, if available, otherwise NULL.
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		/* Make a copy of the path string. */
		path_copy = strdup(path);
		/* The length of the command that was passed */
		command_length = strlen(command);

		/* Get all the directories available by dissecting the path variable. */
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			/* The directory’s length */
			directory_length = strlen(path_token);
		}
			/* allot space to store both the directory name and the command name. */
			file_path = malloc(command_length + directory_length + 2);
			/* Note that we added two to accommodate the slash and null characters */
			/* Let's concatenate the command with the directory path. */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			/* Let's verify that the specified file path actually exists */
			if (stat(file_path, &buffer) == 0)
			{
				/* The file_path is valid if the return value is 0, which is success. */

				/* Before returning your file_path, free up any alloted space */
				free(path_copy);
				return (file_path);
			}
			else
			{
				/* Release the file_path memory so that we can look for another path. */
				free(file_path);
			}
			path_token = strtok(NULL, ":");
	}
	/* We return NULL if no file_path is returned for the command */
	free(path_copy);

	/* Check to see if the command itself is a file_path that already exists. */
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}

		return (NULL);
	}

	return (NULL);
}
