#include<stdio.h>

struct process
{
    char name[20];
    int at,bt,ct,tat,wt,st;
}p[10];

void main(){

    int n,att,awt;
    printf("ENTER THE NUMBER OF PROCESSES : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nENTER DETAILS OF PROCESS %d\n", i + 1);
        printf("PROCESS NAME : ");
        scanf(" %s", p[i].name);
        printf("ARRIVAL TIME : ");
        scanf("%d", &p[i].at);
        printf("BURST TIME : ");
        scanf("%d", &p[i].bt);
    }

    //sorting based on the arrival time
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[j].at>p[j+1].at)
            {
                struct process temp  = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            
        }
        
    }


    //?executing
    int clock = 0;
    for (int i = 0; i < n; i++)
    {
        if(p[i].at > clock)
            clock = p[i].at;
        p[i].ct = clock + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;         
        p[i].wt = p[i].tat - p[i].bt;
        p[i].st = p[i].at+p[i].wt;
        awt +=   p[i].wt;
        att +=  p[i].tat;
        clock =  p[i].ct;


    }

    //?Displaying the process

    printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
    for (int i = 0; i < n; i++) {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\nAVERAGE WAITING TIME : %f", (float)awt / n);
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (float)att / n);


    //!printing gantt chart
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < p[i].bt; j++)
        {
             printf(" ");
        }
        printf("%s",p[i].name);
        printf("|    ");        
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d",p[i].st);
        for (int j = 0; j < p[i].bt; j++)
        {
             printf(" ");
        }
        printf("%d    ",p[i].ct);        
    }
    

    
}
