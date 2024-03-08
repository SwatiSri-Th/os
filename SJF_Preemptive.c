// Write a C Program on Shortest Job First Scheduling Algorithm 
//i) Preemptive 
#include <stdio.h>
int i;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process processes[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        for ( i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (shortest == -1 || processes[i].remaining_time < processes[shortest].remaining_time) {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            time++;
        } else {
            processes[shortest].remaining_time--;
            time++;

            if (processes[shortest].remaining_time == 0) 
			{
                completed++;
                processes[shortest].turnaround_time = time - processes[shortest].arrival_time;
                processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
            }
        }
    }
}

void displayResult(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for ( i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, 
		processes[i].arrival_time, 
		processes[i].burst_time, processes[i].turnaround_time, 
		processes[i].waiting_time);
    }
}

int main() {
    int n;
    printf("*************** SJF Preemptive Scheduling ****************\n");
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
        processes[i].remaining_time = processes[i].burst_time;
	}

    calculateTimes(processes, n);
    printf("\n");
    displayResult(processes, n);

    return 0;
}


