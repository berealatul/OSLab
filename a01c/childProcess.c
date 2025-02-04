#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Child Process Executed: %s\n", argv[0]);
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    printf("Child Program Finished\n");
    return 0;
}
