#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int currPID = getpid();
    int currPPID = getppid();

    printf("currPID: %d\n", currPID);
    printf("currPPID: %d\n", currPPID);

    pid_t child = fork();

    if (child < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        printf("Child Process Executing execv() function\n");

        // last element must be NULL so that execv() knows where the argument list ends.
        char *argv[] = {"./childProcess", "Hello", "World", NULL};
        execv(argv[0], argv);
    }
    else
    {
        int status;
        wait(&status);
        printf("Returned To Parent Process\nChecking Child Exit Status...\n");

        if (WIFEXITED(status))
            printf("Child process exited successfully\n");
        else
            printf("Child process was unsuccessfull\n");
    }

    return 0;
}