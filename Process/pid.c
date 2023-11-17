
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    int id = fork();
    if(id == 0){
        sleep(1);
    }
    printf("Current ID: %d , Parent ID: %d\n",getpid(),getppid());
    int res=wait(NULL);
    if(res == -1){
        printf("No child to wait for\n");
    }
    else{
        printf("%d finished execution\n", res);
    }
    return 0;

}