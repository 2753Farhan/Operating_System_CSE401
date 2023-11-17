#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;
    int status;

    printf("Parent process (PID: %d) is running.\n", getpid());
    child_pid = fork();

    if (child_pid == 0)
    {
        // Child process


    printf("Child process (PID: %d) is running.\n", getpid());
    exit(42); // Simulate exit with status 42
    printf("Child process (PID: %d) exited normally with status: %d\n", child_pid, WEXITSTATUS(status));
      }
    else if (child_pid > 0)
    {
        wait(&status); // Wait for the child to terminate
        if (WIFEXITED(status))
        {
            printf("Child process (PID: %d) exited normally with status:%d\n", child_pid, WEXITSTATUS(status));
        }
    }
    else
    {
        perror("fork");
        exit(1);
    }
    printf("Parent process is done.\n");
    return 0;

// Parent process
}
