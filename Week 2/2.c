// Implementing Zombie Process
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
int main()
{
    printf("Ved Prakash Nautiyal\tSection C\tStudent ID : 210111216\n");
    int pid = fork();
    // child process 
    if(pid == 0)
    {
        printf("Child Process is Running.\n");
        printf("PID : %d\n", getpid());
        printf("Parent's PID : %d\n", getppid());
        exit(0);
    }
    // parent process
    else
    {
        sleep(10);
        printf("\nParent Process is Running.\n");
        printf("PID : %d\n", getpid());
    }
    return 0;
}