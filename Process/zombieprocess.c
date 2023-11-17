#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//void clean_up_child_process(int signal) {
//    pid_t pid;
//    int status;
//
//    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
//        printf("Removed child process with PID: %d\n", pid);
//    }
//}

int main() {
    pid_t child_pid;

    // Set signal handler for SIGCHLD
//    signal(SIGCHLD, clean_up_child_process);

    // Create child process
    child_pid = fork();
    if (child_pid == 0) {
        // Child process
        printf("Child process is running.\n");
        sleep(2); // Simulate some work
        printf("Child process is done.\n");
        exit(0);
    }
    else if (child_pid > 0) {
        // Parent process
        printf("Parent process created child with PID: %d\n", child_pid);
        sleep(4); // Parent sleeps for a while
        printf("Parent process woke up.\n");
//##############
        int status;
        pid_t terminated_pid;

        while((terminated_pid=wait(&status))>0){
            if(WIFEXITED(status))
                printf("Parent:Child process(PID:%d)terminated with status %d\n",terminated_pid,WEXITSTATUS(status));
            else{
                printf("Parent:Child process(PID:%d)terminated abnormally\n",terminated_pid );
            }
        }
//############### zombie state handled in this block
    }
    else {
        // Error handling
        perror("fork");
        exit(1);
    }

    // Parent process doesn't wait for child
    printf("Parent process is done.\n");
    return 0;
}
