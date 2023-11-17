#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

void handle_sigtstp(int sig){
    printf("Stop korte dibo na\n");
}

int main(){
   // struct sigaction sa;
  //  sa.sa_handler = &handle_sigtstp;
 //   sa.sa_flags = SA_RESTART;
//    sigaction(SIGTSTP, &sa, NULL);

    signal(SIGTSTP,&handle_sigtstp);
    int x;
    printf("Input number: ");
    scanf("%d",&x);
    printf("Result %d * 5 = %d\n",x,x*5);

    return 0;
}
//SIGCHILD
//SIGSTOP
//SIGCON

