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

    int childCount = 0;
    int grandChildCount = 0;

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

        int grandChild = fork();
        if (grandChild < 0)
        {
            printf("Fork Failed!\n");
            exit(1);
        }
        else if (grandChild == 0)
        {
            // new grandChild
            int grandChildPID = getpid();
            int grandChildPPID = getppid();

            printf("grandChildPID: %d\n", grandChildPID);
            printf("grandChildPPID: %d\n", grandChildPPID);

            printf("rollNumber: CSM24006\n");

            exit(0);
        }
        else
        {
            printf("Returning To Child After grandChild Processesed!\n");
            grandChildCount++;

            int parentPID = getpid();
            int parentPPID = getppid();

            printf("parentPID: %d\n", parentPID);
            printf("parentPPID: %d\n", parentPPID);

            exit(0);
        }
    }
    else
    {
        printf("Returning To Parent After Child Processesed!\n");
        childCount++;

        int parentPID = getpid();
        int parentPPID = getppid();

        printf("parentPID: %d\n", parentPID);
        printf("parentPPID: %d\n", parentPPID);

        printf("childCount: %d\n", childCount);
        printf("grandChildCount: %d\n", grandChildCount);
    }

    return 0;
}