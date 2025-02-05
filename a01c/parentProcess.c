#include <stdio.h>
#include <unistd.h>

int main()
{
    int currPID = getpid();
    int currPPID = getppid();

    printf("currPID: %d\n", currPID);
    printf("currPPID: %d\n", currPPID);

    return 0;
}