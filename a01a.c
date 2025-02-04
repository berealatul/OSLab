#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Hello, World\n");

    int currentPID = getpid();
    int currentPPID = getppid();

    printf("currentPID: %d\n", currentPID);
    printf("currentPPID: %d\n", currentPPID);

    int child = fork();
    /*
        fork returns three kinds of value
        > 0     : returning to parent process
        == 0    : creating child process
        < 0     : failed to create fork
    */

    if (child < 0)
    {
        printf("Fork Failed\n");
        exit(0);
    }
    else if (child == 0)
    {
        // new child
        int childPID = getpid();
        int childPPID = getppid();

        printf("childPID: %d\n", childPID);
        printf("childPPID: %d\n", childPPID);
    }
    else
    {
        printf("Returning To Parent After Child Processesed!\n");

        int parentPID = getpid();
        int parentPPID = getppid();

        printf("parentPID: %d\n", parentPID);
        printf("parentPPID: %d\n", parentPPID);
    }

    return 0;
}