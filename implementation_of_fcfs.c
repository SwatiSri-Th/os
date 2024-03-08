// implementation of fcfs :

#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main()
{
	system("color 3f");
	int p_id[15]; //process ID
	int b_t[15];	//Burst Time
	int n;	//Number of processes
	int i;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);
	
	printf("Enter the process ID of all the Processes : \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&p_id[i]);
	}
	
	printf("Enter Burst Time of all the processes : \n");
	for( i = 0; i< n; i++)
	{
		scanf("%d",&b_t[i]);
	}
	int w_t[n];	//waiting time
	w_t[0] = 0;
	
	//calculating the waiting time of each process : 
	for(i = 1; i < n; i++)
	{
		w_t[i] = b_t[i - 1] + w_t[i - 1];
	}
	printf("Process ID \t Burst Time 	\tWaiting Time	 \tTurnAroundTime : \n");
	float t_w_t = 0.0;	//Total Waiting Time
	float t_a_t = 0.0;	// Turn Around Time
	for(i = 0; i < n ; i++)
	{
		printf("%d\t\t     ",p_id[i]);
		printf("%d\t\t\t\t",b_t[i]);
		printf("%d\t\t\t\t",w_t[i]);
		
		
		//calculating and printing turnaround time of each process : 
		printf("%d\t\t",b_t[i] + w_t[i]);
		printf("\n");
		
		//calculating total waiting time.
		
		t_w_t += w_t[i];
		
		//for calculating  turnaround time
		t_a_t += (w_t[i] + b_t[i]);
	}
	float a_t_t, a_w_t;
	
	//for calculating average waiting time .
	
	a_w_t = t_w_t/n;
	
	//for calculating average turnaround time.
	
	a_t_t = t_a_t/n;
	printf("Average Waiting Time = %f\n",a_w_t);
	printf("Average TurnAroundTime = %f\n",a_t_t);
	
	return 0;
}

