    /*
    ## Markdown in a C File

    You can include Markdown content within C-style comments.
    - This won't affect the functionality of your C code.
    - It's useful for adding documentation and explanations.
    */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function( void *ptr );

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int itr1,itr2;

    itr1 = pthread_create( &thread1, NULL , print_message_function, (void*) message1);
    itr2 = pthread_create( &thread2, NULL , print_message_function, (void*) message2);

    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);

    printf("Thread 1 returns: %d\n",itr1);
    printf("Thread 2 returns: %d\n",itr2);
    exit(0);
}

void *print_message_function(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s \n",message);
}
