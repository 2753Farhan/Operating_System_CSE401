
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(){
    int pid = fork();
    if (pid == -1){
        return 1;
    }

    if(pid == 0){
            //execlp("ping","ping","-c","3","google.com",NULL);
            execlp("ping","ping","google.com",NULL);

    }
    else {
        wait(NULL);
        printf("ftfrdfgfddxgd\n");
    }

    return 0;
}
