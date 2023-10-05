//Question No. 4 - FCFS Scheduling 
// Calculate atat, awt, cpu utilisation (cu), throughput (tp)
// Print Table Too

#include <stdio.h>

typedef struct process
{
    float pid,at,bt,ct,tat,wt;
}pro;

int comp(const void *a, const void *b)
{
    pro *p1 = (pro *)a;
    pro *p2 = (pro *)b;
    return p1->at > p2->at;
}

int main()
{
    printf("Enter Number Of Processes : ");
    int n;
    scanf("%d",&n);
    float atat,awt,cu,tp,idle;
    pro process[n];
    for (int i=0;i<n;i++)
    {
        process[i].pid=i+1;
        printf("Enter arrival time of %d process : ",i+1);
        scanf("%f",&process[i].at);
        printf("Enter burst time of %d process : ",i+1);
        scanf("%f",&process[i].bt);
    }

    qsort(process, n, sizeof(pro), comp);

    process[0].ct=process[0].at+process[0].bt;
    for(int i=1;i<n;i++)
    {
        if(process[i].at>=process[i-1].ct)
        {
            process[i].ct=process[i].at+process[i].bt;
            idle+=process[i].at-process[i-1].ct;
        }
        else
        {
            process[i].ct=process[i-1].ct+process[i].bt;
        }
    }

    for(int i=0;i<n;i++)
    {
        process[i].tat=process[i].ct-process[i].at;
        process[i].wt=process[i].tat-process[i].bt;
        atat+=process[i].tat;
        awt+=process[i].wt;
    }
    printf("PID \tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0;i<n;i++)
    {
        printf("%d \t%0.0f\t%.0f\t%.0f\t%.0f\t%.0f\n",i+1,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);
    }
    cu=((process[n-1].ct-idle)/process[n-1].ct)*100;
    atat=atat/n;
    awt=awt/n;
    tp=n/process[n-1].ct;
    printf("\n\nCPU Utilisation = %f\nAverage TAT = %f\nAverage WT = %f\nThroughput = %f\n",cu,atat,awt,tp);
}