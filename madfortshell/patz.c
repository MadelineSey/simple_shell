#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH_LEN 1024

int main(){
/*function to find command path*/

char *find_cmd_path(char* command)

	char* path = getenv("PATH");
		char* dir = strtok(path, ":");

	char comd_path[MAX_PATH_LEN];

	while (dir != NULL){
		strncpy(comd_path, dir, MAX_PATH_LEN);
		strncat(comd_path, "/", MAX_PATH_LEN - strlen(comd_path) - 1);
		strncat(comd_path, buffer, MAX_PATH_LEN - strlen(comd_path) -1);

		if (access(comd_path, X_OK) == 0) {
			return strdup(cmd_path);
		}

		dir = strtok(NULL, ":");
	}

	return "";
}
