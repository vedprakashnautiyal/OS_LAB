#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Ved Prakash Nautiyal\tSection C\tStudent ID : 210111216\n");
    fork();
    printf("Hello, World! From Process %d\n",getpid());
}