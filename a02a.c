#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void handleSignal(int sig)
{
    printf("\nInterrut Signal Recieved\n");
    pid_t child = fork();

    if (child < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        printf("Child Process: \n");
        printf("    childPID: %d\n", getpid());
        printf("    childPPID: %d\n", getppid());
    }
    else
    {
        wait(NULL);
        printf("Parent Process: \n");
        printf("    parentPID: %d\n", getpid());
        printf("    childPID: %d\n", child);
    }

    exit(0);
}

int main()
{
    int counter = 0;
    printf("Time Elapsed: ");

    // register signal handler for SIGINT (Ctrl + C)
    signal(SIGINT, handleSignal);

    while (1)
    {
        printf("%d ", counter++);
        sleep(1);
    }

    return 0;
}