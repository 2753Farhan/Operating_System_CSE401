#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define N 100
int freq[N];

void updateFreq(int arr[],int n)
{
    for(int i=0;i<n;i++) freq[arr[i]]++;
}

int evenSum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0) sum+=arr[i];
    }
    return sum;
}

int evenNum(int arr[],int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0) cnt++;
    }
    return cnt;
}

void sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main()
{
    int n=5;
    int arr[]={4,9,2,6,3};
    printf("Parent process:\n");
    updateFreq(arr,n);
    for(int i=0;i<n;i++) printf("freq[%d]: %d\n", arr[i],freq[arr[i]]);
    int root_id=getpid();
    int firstchild_id=-1;
    fork();
    if(root_id!=getpid())
    {
        printf("Child 1: ");
        printf("Even sum: %d\n", evenSum(arr,n));
        firstchild_id=getpid();
    }

    fork();
    if(firstchild_id==getppid()){
    
            printf("Child 3: ");
            sort(arr,n);
            printf("Sorted Array: ");
            for(int i=0;i<n;i++) printf("%d ", arr[i]);
            printf("\n");

    }
    else if(root_id==getppid()&&firstchild_id!=getpid())
    {
            printf("Child 2: ");
            printf("Even numbers: %d\n", evenNum(arr,n));
    }
}

