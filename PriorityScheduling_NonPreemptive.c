// Write a C program for Priority Scheduling Algorithm

//i) Non- Preemptive : 

#include <stdio.h>
int i,j;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int turnaround_time;
    int waiting_time;
};

void sortProcessesByArrivalTime(struct Process processes[], int n) {
    for (i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void sortProcessesByPriority(struct Process processes[], int n) {
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(struct Process processes[], int n) {
    sortProcessesByArrivalTime(processes, n);
    int time = processes[0].arrival_time;
    int total_completion_time = 0;

    for ( i = 0; i < n; i++) {
        sortProcessesByPriority(processes, n);

        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }

        time += processes[i].burst_time;
        processes[i].turnaround_time = time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_completion_time += processes[i].turnaround_time;
    }
}

void displayResult(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].priority, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    int n, i;
    printf("*************** Priority Scheduling ****************\n");
    printf("\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
	printf("\n");
    struct Process processes[n];
    printf("***************Enter the values for Arrival time**********\n");
    printf("\n");
    for ( i = 0; i < n; i++) 
	{
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }
    printf("\n");
	printf("***************Enter the values for Burst time**********\n");
	printf("\n");
	for(i = 0; i< n; i++)
	{
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
 	}
 	printf("\n");
	printf("***************Enter the values for Priority time**********\n");
	printf("\n");
	for(i = 0; i< n; i++)
	{
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
	}
	printf("\n");
    calculateTimes(processes, n);
    printf("\n");
    displayResult(processes, n);

    return 0;
}

