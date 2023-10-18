#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/* Function prototypes */
void display_prompt(void);
void read_user_input(char *input, char *args[]);
void execute_command(char *args[]);

#endif /* SHELL_H */

