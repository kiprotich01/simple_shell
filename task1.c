#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main(void) {
    while (1) {
        char input[MAX_INPUT_LENGTH];
        char *args[MAX_INPUT_LENGTH / 2];  // Assuming maximum 512 arguments

        printf("$ ");  // Display the shell prompt

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");  // Handle Ctrl+D
            break;
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Tokenize the input into arguments
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;  // Null-terminate the arguments list

        if (i == 0) {
            continue;  // Empty input, prompt again
        }

        pid_t child_pid = fork();
        if (child_pid == 0) {
            // Child process
            execvp(args[0], args);

            // If execvp returns, it means the command is not found
            perror("Command not found");
            exit(1);
        } else if (child_pid < 0) {
            // Fork error
            perror("Fork failed");
        } else {
            // Parent process
            int status;
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
                // Command not found
                printf("Command not found\n");
            }
        }
    }

    return 0;
}

