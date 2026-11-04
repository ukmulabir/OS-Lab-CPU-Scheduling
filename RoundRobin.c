
#include <stdio.h>

struct Process {
    int pid, at, bt, rem, ct, tat, wt;
};

int main() {
    int n, tq, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        p[i].rem = p[i].bt;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    if (tq <= 0) {
        printf("Time Quantum must be positive.\n");
        return 1;
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int queue[n + 1];
    int front = 0, rear = 0;
    int next = 0;

    while (completed < n) {

        // Add newly arrived processes
        while (next < n && p[next].at <= time) {
            queue[rear++] = next++;
        }

        if (front == rear) {
            if (next < n) {
                time = p[next].at;
                continue;
            }
            break;
        }

        int idx = queue[front++];

        int run = (p[idx].rem < tq) ? p[idx].rem : tq;

        time += run;
        p[idx].rem -= run;

        // Add processes that arrived during execution
        while (next < n && p[next].at <= time) {
            queue[rear++] = next++;
        }

        if (p[idx].rem == 0) {
            p[idx].ct = time;
            completed++;
        } else {
            queue[rear++] = idx;
        }
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
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
