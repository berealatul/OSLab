#include <stdio.h>
#include <sys/types.h>

// container to store process action
struct processAction
{
    pid_t pid;
    int sig;
};

struct processAction takeInput()
{
    struct processAction pa;

    printf("Enter PID of process to kill: ");
    scanf("%d", &pa.pid);

    printf("Enter signal number to send: ");
    scanf("%d", &pa.sig);

    return pa;
}

int main()
{
    struct processAction pa = takeInput();

    printf("PID: %d\n", pa.pid);
    printf("Signal: %d\n", pa.sig);

    return 0;
}