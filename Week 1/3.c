#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main()
{
    printf("Enter Number - ");
    int n;
    scanf("%d", &n);

    int x=fork();

    if(x==0)
    {
        int num=n;
        int sum=0;
        while(num!=0)
        {
            sum=sum*10+num%10;
            num/=10;
        }
        if(sum==n)
        {
            printf("The Number Is Palindrome \n");
        }
        else
        {
            printf("Not A Palindrome \n");
        }
    }
    else
    {
        int counter=0;
        for (int i = 2 ;i<=sqrt(n);++i)
            {
                if(n%i==0)
                    counter++;
            }
        if(counter!=0)
        {   
            printf("Not A Prime \n");
        }
        else
        {
            printf("The Number Is Prime \n");
        }
    }
    
}