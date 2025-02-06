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
    printf("Hello World\n");
}

int main()
{
    printf("Running thread...\n");
    pthread_t thread;
    pthread_create(&thread, NULL, threadFunction, NULL);
    printf("Parent Completed\n");

    return 0;
}