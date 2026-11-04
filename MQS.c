
#include <stdio.h>

int main() {
    int n, i, time = 0, quantum;
    int pid[20], at[20], bt[20], rt[20];
    int queue[20], ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int q1_count = 0, q2_count = 0;
    int done, index;
    float avg_tat = 0, avg_wt = 0;

    printf("Multilevel Queue Scheduling\n");
    printf("Q1: Round Robin (High Priority)\n");
    printf("Q2: FCFS (Low Priority)\n\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum for Q1: ");
    scanf("%d", &quantum);

    if (n <= 0 || n > 20 || quantum <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nProcess P%d\n", pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Queue (1 = RR, 2 = FCFS): ");
        scanf("%d", &queue[i]);

        if (at[i] < 0 || bt[i] <= 0 ||
            (queue[i] != 1 && queue[i] != 2)) {
            printf("Invalid process information!\n");
            return 1;
        }

        rt[i] = bt[i];

        if (queue[i] == 1)
            q1_count++;
        else
            q2_count++;
    }

    // Execute Q1 using Round Robin
    while (1) {
        done = 1;

        for (i = 0; i < n; i++) {
            if (queue[i] == 1 && rt[i] > 0) {
                done = 0;

                if (time < at[i])
                    time = at[i];

                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed[i] = 1;
                }
            }
        }

        if (done)
            break;
    }

    // Execute Q2 using FCFS
    while (1) {
        index = -1;

        for (i = 0; i < n; i++) {
            if (queue[i] == 2 && !completed[i]) {
                if (index == -1 || at[i] < at[index])
                    index = i;
            }
        }

        if (index == -1)
            break;

        if (time < at[index])
            time = at[index];

        time += bt[index];
        ct[index] = time;
        completed[index] = 1;
    }

    // Calculate TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\n\nMultilevel Queue Scheduling Result\n");
    printf("---------------------------------------------\n");
    printf("PID\tQueue\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("P%d\tQ%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], queue[i], at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    printf("---------------------------------------------\n");

    printf("Average Turnaround Time: %.2f\n", avg_tat / n);
    printf("Average Waiting Time: %.2f\n", avg_wt / n);

    printf("\nQ1 Processes: %d\n", q1_count);
    printf("Q2 Processes: %d\n", q2_count);

    return 0;
}
