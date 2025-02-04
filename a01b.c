#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utmp.h>

void printLoggedUsers()
{
    struct utmp *entry;

    // open utmp file
    setutent();

    printf("Logged Users List Started:\n");

    while ((entry = getutent()) != NULL)
    {
        if (entry->ut_type == USER_PROCESS)
        {
            printf("User: %s\n", entry->ut_user);
        }
    }

    printf("Logged Users List Over\n");

    // close utmp file
    endutent();
}

int main()
{
    printf("Hello, World\n");

    int currentPID = getpid();
    int currentPPID = getppid();

    printf("currentPID: %d\n", currentPID);
    printf("currentPPID: %d\n", currentPPID);

    pid_t child = fork();
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

        pid_t grandChild = fork();
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
            wait(NULL);

            printf("Returning To Child After grandChild Processesed!\n");
            grandChildCount++;

            int parentPID = getpid();
            int parentPPID = getppid();

            printf("parentPID: %d\n", parentPID);
            printf("parentPPID: %d\n", parentPPID);

            printLoggedUsers();
            exit(0);
        }
    }
    else
    {
        wait(NULL);

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