#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handleSignal(int sig)
{
    printf("\nInterrut Signal Recieved\n");
    // TODO
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