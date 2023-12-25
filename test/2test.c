#include "testmain.h"

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("simple_shell> "); // Display the prompt
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); // Handle Ctrl+D (EOF)
            break;
        }

        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

        pid_t pid = fork(); // Create a child process

        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execlp(input, input, NULL); // Execute the command
            // If execlp fails, print an error message
            printf("Command not found: %s\n", input);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0); // Wait for the child process to finish
        }
    }

    return 0;
}
