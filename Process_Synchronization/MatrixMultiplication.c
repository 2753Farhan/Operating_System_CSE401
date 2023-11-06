#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>


static int A[1001][1001], B[1001][1001];
int shmbuf;
key_t key;
int (*ans)[1001];

int main() {

  int m, n, s, r;
  key = ftok(".",'b');
  shmbuf = shmget(key,sizeof(int[1001][1001]),IPC_CREAT|0666);

  if(shmbuf == -1 )
  {
    perror("shmget");
    exit(1);
  }
  ans = shmat(shmbuf,0,0);
  printf("Enter Dimension of matrix A --> m  x n\n");
  scanf("%d %d",&m, &n );

  printf("Enter Dimension of matrix B --> s  x r\n");
  scanf("%d %d",&s, &r );

  if(n!=s){
    printf("Matrix A and B cannot be multiplied.\n");
    exit(0);
  }


  int i, j, k, val;
  printf("Enter the values of matrix A\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      scanf("%d", &A[i][j] );
    }
  }

  printf("Enter the values of matrix B\n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      scanf("%d", &B[i][j] );
    }
  }

  printf("Matrix A looks like:\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d ", A[i][j] );
    }
    printf("\n");
  }

  printf("Matrix B looks like: \n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  printf("Starting multiplcation. During this process %d processes will be created.\n", m*r);
  for(i=0;i<m;i++){
    for(j=0;j<r;j++){
      int pid = fork();
      if(pid == 0){
        val = 0;
        for(k=0;k<n;k++){
          val += A[i][k]*B[k][j];
        }
        printf("value at %d:%d is: %d\n",i, j, val );
        ans[i][j] = val;
        exit(0);

      }
    }

  }

  for(i=0;i<m*r;i++){
    wait(NULL);
  }
  printf("Resultant Matrix is:\n");
  for(i=0;i<m;i++){
    for(j=0;j<r;j++){
      printf("%d ",ans[i][j]);
    }
    printf("\n");
  }

  /* detach shared memory segment */
  shmdt(ans);
  /* remove shared memory segment */
  shmctl(ans, IPC_RMID, NULL);

}
