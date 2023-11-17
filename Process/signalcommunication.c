
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

int x=0;

void handle_sigusr1(int sig){
    if(x == 0 ){
        printf("\n(HINT Remember that multiplication is repetitive addition\n)");
    }
}

int main(){
    int pid = fork();
    if (pid == -1){
        return 1;
    }

    if (pid == 0){
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else{

        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        printf("what is the result of 3 * 6 : ");
        scanf("%d",&x);
        if (x == 18){
            printf("Right!");
        }
        else{
            printf("Wrong!");
        }
        wait(NULL);
    }
}
//SIGCHILD
//SIGSTOP
//SIGCON

