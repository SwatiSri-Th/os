// SJF on Non-Preemptive:

#include <stdio.h>
int i,j;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcessesByArrivalTime(struct Process processes[], int n) {
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculateTimes
(struct Process processes[], int n) {
    sortProcessesByArrivalTime(processes, n);
    int time = processes[0].arrival_time;
    int total_completion_time = 0;

    for ( i = 0; i < n; i++) {
        time += processes[i].burst_time;
        processes[i].turnaround_time = time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_completion_time += processes[i].turnaround_time;
    }
}

void displayResult(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
		 processes[i].burst_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n;
    printf("*************** SJF Non-Preemptive Scheduling ****************\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");
	printf("***************Enter the values for Arrival time**********\n");
    struct Process processes[n];
    printf("\n");
    for ( i = 0; i < n; i++) 
	{
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }
    printf("\n");
	printf("***************Enter the values for Arrival time************ \n\n");
    for (i = 0; i < n; i++)
    {
    	printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
	}
    calculateTimes(processes, n);
    printf("\n");
    displayResult(processes, n);
}
