// Create two processes
//  Using Sleep Function ()
//  When Parent is sleep therefore child will be terminated first then parent, this is called "Zombie Process" because child is terminated but it's id is in still in parent - Parent Sleep
//  And if we make child sleep then parent will sleep first and then child will have no parent, This is known as "Orphan Process" - Child Sleep

//-------------------------------Orphan Process
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Ved Prakash Nautiyal\tSection C\tStudent ID : 210111216\n");

    int pid = fork();

    // child process
    if (pid == 0)
    {
        sleep(5);
        printf("\nChild Process is Running.\n");
        printf("PID : %d\n", getpid());
        printf("Parent's PID : %d\n", getppid());
    }
    else
    {
        // parent process
        printf("Parent Process is Running.\n");
        printf("PID : %d\n", getpid());
        exit(0);
    }
    return 0;
}
