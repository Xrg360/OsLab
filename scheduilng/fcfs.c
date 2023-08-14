#include<stdio.h>

struct process
{
    char name[20];
    int at,bt,ct,tt,wt,st;
}p[10],temp;


int main(){
    int n,awt=0,att=0;
    printf("enter the number of the processes : \n\n");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("\n enter the details of the process%d\n",i+1);
        printf("enter the name of the process : ");
        scanf("%s",p[i].name);
        printf("enter the arrival time of the process");
        scanf("%d",&p[i].at);
        printf("enter the burst time of the process");
        scanf("%d",&p[i].bt);
    }

    //sorting based on arrival time

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j]= p[j+1];
                p[j+1] = temp;
            }
            
        }        
    }

    for (int clock = 0,i=0; i < n; i++)
    {
        if (p[i].at > clock)
        {
            clock = p[i].at;
        }
        p[i].st = clock;
        clock+=p[i].bt;
        p[i].ct = clock;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        awt += p[i].wt;
        att+=p[i].tt;
    }
    
    //printing table
    printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
    for (int i = 0; i < n; i++) {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].ct, p[i].wt, p[i].tt);
    }
    printf("\nAVERAGE WAITING TIME : %f", (float)awt / n);
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (float)att/n);

    
    //printing gantt chart

        printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------------\n\t");

    for (int i = 0; i < n; i++) {
        printf("|%s\t", p[i].name);
    }

    printf(" |\n\t--------------------------------------------------------------------------\n\t");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t", p[i].st);
    }

    printf("%d\t", p[n - 1].ct);
}