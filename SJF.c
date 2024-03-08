// Shortest Job First Scheduling Algorithm 
// i)Non-Preemptive 
// ii) Preemptive : 

#include <stdio.h>
int i,j;
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};
//non - preemptive
void swap(struct Process *a, struct Process *b) 
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

//non preemptive
void sortProcessesByArrivalTime(struct Process processes[], int n) 
{
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}
//non preemptive
void Non_Preemptive_calculateTimes
(struct Process processes[], int n) 
{
    sortProcessesByArrivalTime(processes, n);
    int time = processes[0].arrival_time;
    int total_completion_time = 0;

    for ( i = 0; i < n; i++) 
	{
        time += processes[i].burst_time;
        processes[i].turnaround_time = time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - 
		processes[i].burst_time;
        total_completion_time += processes[i].turnaround_time;
    }
}
// preemptive scheduling 
void calculateTimes(struct Process processes[], int n) {
    int time = 0;
    int completed = 0;

    while (completed < n) 
	{
        int shortest = -1;
        for ( i = 0; i < n; i++) 
		{
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
// Non-preemptive Display
void displayResult(struct Process processes[], int n) 
{
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for ( i = 0; i < n; i++) 
	{
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, 
		processes[i].arrival_time, processes[i].burst_time,
        processes[i].turnaround_time, processes[i].waiting_time);
    }
}

//non preemptive main function
void Non_preemptive_main_function()
{
	int n, choice;
	printf("*************** SJF Scheduling ****************\n");
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
	printf("***************Enter the values for Burst time************ \n\n");
	for (i = 0; i < n; i                                                                        ++)
	{
		printf("Enter burst time for process %d: ", i + 1);
		scanf("%d", &processes[i].burst_time);
	}
	Non_Preemptive_calculateTimes(processes, n);
	printf("\n");
	displayResult(processes, n);
}

void preemptive_main_function()
{
	int n, choice;
	printf("*************** SJF Scheduling ****************\n");
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
	printf("***************Enter the values for Burst time************ \n\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter burst time for process %d : ", i + 1);
		scanf("%d", &processes[i].burst_time);
	}
	calculateTimes(processes, n);
	printf("\n");
	displayResult(processes, n);
}

int main()
{
	int n,choice;
	printf("Performing Shortest Job First Scheduling ! \n");
	printf("\n");
	struct Process processes[n];
	printf("1. Perform A Non - Preemptive Scheduling : \n");
	printf("2. Perform A Preemptive Scheduling : \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : 
			Non_preemptive_main_function();
			break;
		case 2 : 
			preemptive_main_function();
			break;
		default :
			printf("Enter correct choice!");
	}
}
