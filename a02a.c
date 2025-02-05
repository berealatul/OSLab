#include <stdio.h>
#include <unistd.h>

int main()
{
    int counter = 0;
    printf("Time Elapsed: ");

    while (1)
    {
        printf("%d ", counter++);
        sleep(1);
    }

    return 0;
}