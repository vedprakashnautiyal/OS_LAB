#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Ved Prakash Nautiyal\tSection C\tStudent ID : 210111216\n");
    printf("Enter Number Of Elements - ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0 ;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
    int osum=0,esum=0;

    int x=fork();

    if(x==0)
    {
        for (int i = 0 ;i<n;++i)
            {
                if(arr[i]%2==0)
                    esum+=arr[i];
            }
        printf("Sum Of Even Numbers From Process %d is %d \n",getpid(),esum);
    }
    else
    {
        for (int i = 0 ;i<n;++i)
            {
                if(arr[i]%2!=0)
                    osum+=arr[i];
            }
        printf("Sum Of Odd Numbers From Process %d if %d\n",getpid(),osum);
    }
    
}