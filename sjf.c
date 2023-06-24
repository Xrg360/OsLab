//write the code for shortest job first cpu scheduling algorithm in c 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main()
{
    int n, i, j, k, sum=0, sum2=0;
    float avg, avg2;
    printf("Enter the number of processes -- ");
    scanf("%d",&n);
    int bt[n], wt[n], tat[n], p[n], p2[n], wt2[n], tat2[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i+1);
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        sum+=wt[i];
    }
    avg=(float)sum/n;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        sum2+=tat[i];
    }
    avg2=(float)sum2/n;
    printf("\n sjf Scheduling\n");
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
        printf("\n%d \t\t %d \t\t %d \t\t %d",p[i],bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time -- %f",avg);
    printf("\nAverage Turnaround Time -- %f",avg2);
    //display the gantt chart for the processes
    printf("\n\nGantt Chart\n");
    for(i=0;i<n;i++)
        printf("|\tP%d\t",p[i]);
    printf("|\n0\t");
    for(i=0;i<n;i++)
        printf("%d\t",tat[i]);
    printf("\n");


    return 0;
}
