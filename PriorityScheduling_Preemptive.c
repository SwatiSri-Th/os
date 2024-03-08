// Priority Scheduling Preemptive

//ii) non preemtive

#include <stdio.h>
int i;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process processes[], int n) 
{
    int time = 0;
    int completed = 0;

    while (completed < n) 
	{
        int highest_priority = -1;
        for ( i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority) {
                    highest_priority = i;
                }
            }
        }
        if (highest_priority == -1) {
            time++;
        } else {
            processes[highest_priority].remaining_time--;
            time++;

            if (processes[highest_priority].remaining_time == 0) {
                completed++;
                processes[highest_priority].turnaround_time = time - processes[highest_priority].arrival_time;
                processes[highest_priority].waiting_time = processes[highest_priority].turnaround_time - processes[highest_priority].burst_time;
            }
        }
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
