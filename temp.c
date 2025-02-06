#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Required for pthread functions
#include <unistd.h>  // Required for sleep()

// Thread function that runs in the created thread
void *threadFunction()
{
    printf("HELLO WORLD from Thread!\n");

    // Exit the thread properly
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread; // Thread identifier
    int status;

    // Creating a new thread
    status = pthread_create(&thread, NULL, threadFunction, NULL);
    if (status != 0)
    {
        printf("Thread unsucessfull\n");
        return 1;
    }

    printf("Main thread: Created a new thread.\n");

    // Wait for the created thread to finish execution
    // pthread_join(thread, NULL);

    printf("Main thread: Child thread has finished execution.\n");

    return 0;
}
