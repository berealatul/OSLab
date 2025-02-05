#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Running Signal Reciever\n");
    printf("PID: %d\n", getpid());

    printf("Waiting for signals...\n");

    int counter = 0;
    printf("Time Elapsed: ");
    while (1)
    {
        printf("%d ", counter++);
        sleep(1);
    }

    return 0;
}