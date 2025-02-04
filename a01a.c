#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello, World\n");

    int currentPID = getpid();
    int currentPPID = getppid();

    printf("currentPID: %d\n", currentPID);
    printf("currentPPID: %d\n", currentPPID);

    return 0;
}