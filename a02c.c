/*
Write a C program to create a user level thread using system call pthread_create( )
and assign the thread to display the “HELLO WORLD” .
Use pthread_exit() in your program (if possible) for terminating the thread.
*/

#include <stdio.h>
#include <pthread.h>

// since c does not have facility to accept generic data type so casting using (void*) to resolve it
void *threadFunction()
{
    printf("    Thread: \n\t");
    printf("Hello World\n");

    // terminate the thread using default attribute by passing NULL
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    // NULL indicates default thread attributes
    int status = pthread_create(&thread, NULL, threadFunction, NULL);
    if (status != 0)
    {
        printf("Thread unsucessfull\n");
        return 1;
    }

    printf("Main Program: thread created sucessfully\n");

    // wait for thread to complete
    pthread_join(thread, NULL);
    printf("Main Program: thread finished esecution\n");

    return 0;
}