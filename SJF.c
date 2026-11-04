
#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt, completed;
};

int main() {
    int n, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].completed = 0;

        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    while (completed < n) {
        int idx = -1;
        int minBT = 999999;

        // Find the shortest available process
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time &&
                p[i].completed == 0 &&
                p[i].bt < minBT) {

                minBT = p[i].bt;
                idx = i;
            }
        }

        // CPU remains idle if no process is available
        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        p[idx].completed = 1;
        completed++;

        avgWT += p[idx].wt;
        avgTAT += p[idx].tat;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt,
            p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);

    return 0;
}
