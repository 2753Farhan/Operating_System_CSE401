#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int fd[2];
    if(pipe(fd) == -1){
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if(id == -1){
        return 2;
    }
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arrsize = sizeof(arr)/sizeof(int);
    int start,end;

    if(id== 0 ){
         start = 0;
         end = start + arrsize/2;
    }
    else{
        start = arrsize/2;
        end = arrsize;
    }
    int sum=0;
    for (int i=start;i <end ;i++){
        sum += arr[i];
    }
    printf("calculated sum : %d\n",sum);
}
