// Round Robin Scheduling Algorithm : 

#include <stdio.h>
#include <stdbool.h>
int i;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process processes[], int n, int time_quantum) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        bool process_executed = false;

        for ( i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                process_executed = true;

                if (processes[i].remaining_time <= time_quantum) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;

                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                } else {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                }
            }
        }

        if (!process_executed) {
            time++;
        }
    }
}

void displayResult(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n, time_quantum;
     printf("*************** Round Robin Scheduling ****************\n");
    printf("\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
	printf("\n");
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
	printf("\n");
    struct Process processes[n];
    for ( i = 0; i < n; i++) 
	{
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }
    printf("\n");
	printf("***************Enter the values for Burst time**********\n");
	printf("\n");
    for(i = 0; i< n;i++)
    {
    	printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
	}
	printf("\n");
    calculateTimes(processes, n, time_quantum);
    printf("\n");
    displayResult(processes, n);

    return 0;
}
