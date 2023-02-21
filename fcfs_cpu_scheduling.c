#include<stdio.h>

void FCFS()
{
	int ct[10],bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},rtime;
	int p[10];
	int n,sum=0;
	float totalTAT=0,totalWT=0;

	printf("Enter number of process:");
	scanf("%d",&n);

	printf("Enter Process_No, BT, AT\n");

	for(int i=0;i<n;i++)
	{
	    printf("P");
        scanf("%d",&p[i]);
		scanf("%d",&bt[i]);
		scanf("%d",&at[i]);
	}
    int curr_t=at[0];
    printf("\nGantt Chart\n");
    printf("%d",curr_t);
      for(int i=0; i<n; i++)
      {
          printf(" |--P%d--| ",p[i]);
          curr_t = curr_t + bt[i];
          ct[i]=curr_t;
          tat[i] = curr_t - at[i];
          wt[i] = tat[i] - bt[i];
          totalWT = totalWT + wt[i];
          totalTAT = totalTAT + tat[i];
          if(i < n-1 && curr_t<at[i+1])
          {   
            printf("|-IDLE-|");                          // checks if cpu is ideal
            curr_t = at[i+1];
            printf("%d",curr_t);
          }
          printf("%d",curr_t);
      }
    
    
	printf("\nOUTPUT: \n\n");
	printf("P#\t BT\t AT\tWT\t TAT\t CT\n\n");

	for(int i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",p[i],bt[i],at[i],wt[i],tat[i],ct[i]);
	}

	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);


}

int main()
{
    printf("First Come First Serve Scheduling Algorithm\n"); 
    FCFS();
	return 0;
}
