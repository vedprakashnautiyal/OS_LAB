//SRTF Scheduling

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct process
{
    int at, bt, pro, ct, tat, wt, rt, pid, bt_remaining, is_completed;
} pro;

int comp(const void *a, const void *b)
{
    pro *p1 = (pro *)a;
    pro *p2 = (pro *)b;
    return p1->at > p2->at;
}

void averageTime(pro *process, int n, float idle)
{
    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += process[i].wt;
        total_tat += process[i].tat;
        total_rt += process[i].rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i].pid, process[i].at, process[i].bt, process[i].ct, process[i].tat, process[i].wt, process[i].rt);
    }

    printf("\nAverage Waiting time %.2f\n", total_wt / (float)n);
    printf("Average Turn Around time %.2f\n", total_tat / (float)n);
    printf("Average Response time %.2f\n", total_rt / (float)n);
    printf("CPU utilization %.2f\n", ((process[n - 1].ct - idle) / (float)process[n - 1].ct) * 100);
    printf("Throughput %.2f\n", (float)n / (process[n - 1].ct - process[0].at));
}

int main()
{

    int n;
    printf("Enter the Number of Processes : ");
    scanf("%d", &n);

    pro process[n];

    for (int i=0;i<n;i++)
    {
        process[i].pid=i+1;
        printf("Enter arrival time of %d process : ",i+1);
        scanf("%d",&process[i].at);
        printf("Enter burst time of %d process : ",i+1);
        scanf("%d",&process[i].bt);
        process[i].bt_remaining = process[i].bt;
        process[i].is_completed = 0;
    }

    int current_time = 0, completed = 0, idle = 0, prev = 0;
    qsort(process, n, sizeof(pro), comp);

    while (completed != n)
    {
        int idx = -1, mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (process[i].at <= current_time && process[i].is_completed == 0)
            {
                if (process[i].bt_remaining < mn)
                {
                    mn = process[i].bt_remaining;
                    idx = i;
                }

                if (process[i].bt_remaining == mn)
                {
                    if (process[i].at < process[idx].at)
                    {
                        mn = process[i].bt_remaining;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            if (process[idx].bt_remaining == process[idx].bt)
            {
                process[idx].pro = current_time; // start time
                idle += process[idx].pro - prev;
            }

            process[idx].bt_remaining -= 1;
            current_time++;
            prev = current_time;

            if (process[idx].bt_remaining == 0)
            {
                process[idx].ct = current_time;               // completion time
                process[idx].tat = process[idx].ct - process[idx].at; // turn around time
                process[idx].wt = process[idx].tat - process[idx].bt; // waiting time
                process[idx].rt = process[idx].pro - process[idx].at;  // response time
                process[idx].is_completed = 1;
                completed++;
            }
        }

        else
        {
            current_time++;
        }
    }

    averageTime(process, n, idle);
}