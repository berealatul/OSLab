#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int sig)
{
    printf("\nSignal Recieved: %d\n", sig);
    exit(0);
}

int main()
{
    printf("Running Signal Reciever\n");
    printf("PID: %d\n", getpid());

    printf("Waiting for signals...\n");

    // registering all standard signal except SIGKILL(9) & SIGSTOP(19) because it can't be caught or ignored
    for (int i = 1; i < 32; i++)
    {
        if (i != 9 && i != 19)
        {
            signal(i, signalHandler);
        }
    }

    int counter = 0;
    printf("Time Elapsed: ");
    while (1)
    {
        printf("%d ", counter++);
        sleep(1);
    }

    return 0;
}