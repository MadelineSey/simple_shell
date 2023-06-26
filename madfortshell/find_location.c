#include "main.h"

/**
 * get_location - Find the location of the command in the system's PATH.
 *
 * @command: The command to find the location.
 * Return: The complete file path if available, otherwise NULL.
 */
char *get_location(char *command)
{
	char *path = getenv("PATH");

	if (!path)
		return (NULL);
	char *path_copy = strdup(path);

	if (!path_copy)
		return (NULL);

	char *file_path = find_file_path(command, path_copy);

	free(path_copy);

	if (!file_path && file_exists(command))
		return (command);

	return (file_path);
}
/**
 * find_file_path - Find the path of the file for the given command.
 *
 * @command: The command  to find the file path.
 * @path_copy: A copy or duplicate of the system's PATH.
 * Return: The complete file path if available, otherwise NULL.
 */
char *find_file_path(char *command, char *path_copy)
{
	char *path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		char *file_path = build_file_path(command, path_token);

		if (!file_path)
			return (NULL);

		if (file_exists(file_path))
		{
			free(file_path)
			return (file_path);
		}

		free(file_path);
		path_token = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * build_file_path - form the full file path for the given command.
 *
 * @command: The command to form the file path.
 * @directory: The directory where the command might be found.
 * Return: The complete file path.
 */
char *build_file_path(char *command, char *directory)
{
	int command_length = strlen(command);
	int directory_length = strlen(directory);
	char *file_path = malloc(command_length + directory_length + 2);

	if (!file_path)
		return (NULL);
}

	strcpy(file_path, directory);
	strcat(file_path, "/");
	strcat(file_path, command);

	return (file_path);
}

/**
 * file_exists - Check if there is an existing  file at the given path.
 *
 * @file_path: The path of the file to verify
 * Return: 1 if the file exists, otherwise 0
 */
if (stat(command, &buffer) == 0)
{
	return (command);
}
return (NULL);
}
