#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    printf("Enter PID of process to kill: ");
    scanf("%d", &pid);

    int sig;
    printf("Enter Signal ID to send: ");
    scanf("%d", &sig);

    printf("Sending signal to kill PID: %d\n", pid);
    int flag = kill(pid, sig);
    if (flag == 0)
        printf("Sucessfully killed given process\n");
    else
        printf("Failed to kill given process\n");

    return 0;
}