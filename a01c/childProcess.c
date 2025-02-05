#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Child Process Started:\n");

    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    printf("Child Process Completed\n");
    return 0;
}