#include "main.h"

void commandexecute(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        /* Get the command */
        command = argv[0];

        /* Generate the path to this command before passing it to commandexecute */
        actual_command = get_location(command);

        /* Execute the actual command with commandexecute */
        if (commandexecute(actual_command, argv, NULL) == -1) {
            perror("Error executing command");
            exit(1);  // Terminate the program in case of an error
        }
    }
}
