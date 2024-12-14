#include <stdio.h>

#define MAX 10

int main() {
    int n, processes[MAX], burst_time[MAX], priority[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        processes[i] = i + 1;  // Process numbers (1, 2, 3, ..., n)
    }

    // Sorting processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap processes
                int tempProcess = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = tempProcess;

                // Swap priorities
                int tempPriority = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = tempPriority;

                // Swap burst times
                int tempBurstTime = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = tempBurstTime;
            }
        }
    }

    // Calculate waiting time and turnaround time
    int wt[MAX], tat[MAX];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = burst_time[i - 1] + wt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wt[i];
    }

    // Print the result
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f", total_wt / n);
    printf("\nAverage turnaround time: %.2f", total_tat / n);

    return 0;
}
