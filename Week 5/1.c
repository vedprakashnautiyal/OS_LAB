#include <stdio.h>
#include <limits.h>

struct process{
    int pid, at, bt, ct, tat, wt, st, rt;
};

int find_min_remaining(struct process p[], int n, int ct){
    int mini = -1;
    int min_remaining = INT_MAX;
    for(int i=0; i<n; i++){
        if(p[i].at <= ct && p[i].rt > 0 && p[i].rt < min_remaining){
            mini = i;
            min_remaining = p[i].rt;
        }
    }
    return mini;
}

int main(){
    int n;
    scanf("%d", &n);
    struct process p[n];

    // enter at and bt
    for(int i=0; i<n; i++){
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i+1;
        p[i].rt = p[i].bt;
        p[i].st = 0;
    }

    // scheduling
    int completed = 0, ct = 0;
    while(completed != n){
        int mini = find_min_remaining(p, n, ct);
        if(mini == -1){
            ct++;
            continue;
        }
        p[mini].rt--;
        if(p[mini].rt == 0){
            p[mini].ct = ct + 1;
            p[mini].tat = p[mini].ct - p[mini].at;
            p[mini].wt = p[mini].tat - p[mini].bt;
            completed++;
        }
        ct++;
    }

    // printing the table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    // calculating average tat and average wt
    float avg_tat = 0, avg_wt = 0;
    for(int i=0; i<n; i++){
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage TAT: %f\nAverage WT: %f\n", avg_tat, avg_wt);
    return 0;
}

/*
Full Forms of the above variables:
at: arrival time
bt: burst time
ct: completion time
tat: turn around time
wt: waiting time
rt: remaining time
st: start time
*/

/* Algorithm
1. **Initialization:**
   - Define a structure `process` to store process information (PID, arrival time, burst time, completion time, turnaround time, waiting time, start time, remaining time).
   - Create an array `p` of `n` `process` structures to represent the processes.
   - Initialize variables `completed` to 0 (number of completed processes) and `ct` to 0 (current time).

2. **Input Process Data:**
   - Read the number of processes `n` from the user.
   - For each process `i`:
      - Read the arrival time `at[i]` and burst time `bt[i]` of process `i`.
      - Set the process ID `pid[i]` to `i + 1`.
      - Set the remaining time `rt[i]` to the burst time `bt[i]`.
      - Set the start time `st[i]` to 0.

3. **Scheduling:**
   - While there are uncompleted processes (`completed != n`):
      - Find the index `mini` of the process with the minimum remaining time (`rt`) among those that have arrived (`at <= ct`) and are not yet finished (`rt > 0`).
         - If no such process exists, increment the current time `ct` and continue.
      - Decrement the remaining time (`rt`) of the selected process `p[mini]`.
      - If the remaining time of the selected process becomes zero (`rt == 0`), update its completion time (`ct`), turnaround time (`tat`), and waiting time (`wt`).
         - Increment the number of completed processes (`completed`).
      - Increment the current time `ct`.

4. **Output Results:**
   - Print a table summarizing the process information: PID, arrival time, burst time, completion time, turnaround time, and waiting time.
   - Calculate and print the average turnaround time (`avg_tat`) and average waiting time (`avg_wt`).
*/
