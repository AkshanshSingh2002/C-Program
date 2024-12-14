#include <stdio.h>

#define MAX_PROCESSES 30

// Function to calculate average waiting time and average turnaround time
void calculateAverages(int n, int bt[], int tat[], int wt[], float *awt, float *atat) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        *awt += wt[i];
        *atat += tat[i];
    }

    *awt /= n;
    *atat /= n;
}

int main() {
    int n, bt[MAX_PROCESSES], tat[MAX_PROCESSES], wt[MAX_PROCESSES], rem_bt[MAX_PROCESSES];
    int qt, count = 0, temp, sq = 0;

    float awt = 0.0, atat = 0.0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    printf("Enter the burst time of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    // Input quantum time
    printf("Enter quantum time: ");
    scanf("%d", &qt);

    // Calculate turnaround time using Round Robin scheduling
    while (1) {
        int done = 1; // Flag to check if all processes are done

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There are still processes remaining

                if (rem_bt[i] > qt) {
                    rem_bt[i] -= qt;
                    sq += qt;
                } else {
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                    tat[i] = sq;
                }
            }
        }

        if (done)
            break; // All processes are done
    }

    // Display process information
    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], tat[i] - bt[i]);
    }

    // Calculate and display average waiting time and average turnaround time
    calculateAverages(n, bt, tat, wt, &awt, &atat);
    printf("\nAverage Waiting Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);

    return 0;
}
