#include <stdio.h>
#include <string.h>

int main() {
    int n, i, completed = 0, time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    char pid[n][10];
    int at[n], bt[n], pr[n];
    int wt[n], tat[n];
    int done[n];

    for(i = 0; i < n; i++)
        done[i] = 0;

    printf("Enter PID AT BT PR:\n");
    for(i = 0; i < n; i++) {
        scanf("%s %d %d %d", pid[i], &at[i], &bt[i], &pr[i]);
    }

    while(completed < n) {
        int idx = -1;
        int highest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(pr[i] > highest) {
                    highest = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            wt[idx] = time - at[idx];
            if(wt[idx] < 0)
                wt[idx] = 0;

            time += bt[idx];
            tat[idx] = wt[idx] + bt[idx];

            done[idx] = 1;
            completed++;

            avg_wt += wt[idx];
            avg_tat += tat[idx];
        } else {
            time++;
        }
    }

    printf("\nWaiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
