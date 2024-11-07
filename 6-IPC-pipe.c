// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int main() {
//     int pipe1[2], pipe2[2];
//     pid_t pid;
//     char parentMessage[] = "Hello from parent!";
//     char childMessage[] = "Hello from child!";
//     char buffer[100];

//     // Create the pipes
//     if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
//         perror("Pipe creation failed");
//         exit(1);
//     }

//     // Fork to create child process
//     pid = fork();

//     if (pid < 0) {
//         perror("Fork failed");
//         exit(1);
//     }

//     if (pid > 0) {
//         // Parent process
//         close(pipe1[0]); // Close reading end of pipe1
//         close(pipe2[1]); // Close writing end of pipe2

//         // Send message to child
//         write(pipe1[1], parentMessage, strlen(parentMessage) + 1);
//         close(pipe1[1]); // Close writing end after sending

//         // Read child's response
//         read(pipe2[0], buffer, sizeof(buffer));
//         printf("Parent received: %s\n", buffer);
//         close(pipe2[0]); // Close reading end
//     } else {
//         // Child process
//         close(pipe1[1]); // Close writing end of pipe1
//         close(pipe2[0]); // Close reading end of pipe2

//         // Read message from parent
//         read(pipe1[0], buffer, sizeof(buffer));
//         printf("Child received: %s\n", buffer);
//         close(pipe1[0]); // Close reading end

//         // Send response to parent
//         write(pipe2[1], childMessage, strlen(childMessage) + 1);
//         close(pipe2[1]); // Close writing end
//     }

//     return 0;
// }
