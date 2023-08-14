#include<stdio.h>
#include<stdlib.h>

#define MAXP 20
#define MAXQ 100

struct process
{
    char name[20];
    int at,bt,ct,wt,status,remaining,ct,tt;
}p[MAXP],temp;

struct done
{
    char name[20];
    int st,ct;
}d[MAXQ];

int q[MAXQ],front = -1,rear = -1;

void enqueue(int j){
    if(front == -1){
        front++;
    }
    q[++rear] = j;
}

int dequeue(){
    int item  = q[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else
        front++;
    return item;
}

int main(){
    int n,tempindex,idle=0,ls,t;
    float awt=0,att=0;

    printf("enter the number of processes : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Details of the proces %d\n",i+1);
        printf("process name : ");
        scanf("%s",p[i].name);
        printf("ARRIVAL TIME : ");
        scanf("%s",&p[i].at);
        printf("BURST TIME : ");
        scanf("%s",&p[i].bt);
        p[i].remaining = p[i].bt;
        p[i].status = 0;
    }

    printf("enter the time quantum : ");
    scanf("%d",&t);

    int clock = 0;
    int k = 0;    //for adding the elements to the d array;
    for (int num = 0; num < n; num++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[j].status == 0 && p[j].at <= clock)
            {
                enqueue(j);
                p[j].status = 1;
            }            
        }    // for adding the processes which is going to be added to the queue fro the first tiem 


        if (idle == 0 && front == -1)
        {
            strcpy(d[k].name,"idle");
            d[k].st = clock;
            idle = 1;
            clock++;
        }
        
        else if(front!=-1){
            if (idle==1)
            {
                d[k].ct = clock;
                idle = 0 ;
                k++;
            }
            tempindex = dequeue();
            d[k].st = clock;
            strcpy(d[k].name,p[tempindex].name);
            if (p[tempindex].remaining <= t)
            {
                d[k].ct = clock + p[tempindex].remaining;
                p[tempindex].ct = d[k].ct;
                clock = d[k].ct;

                p[tempindex].tt = clock - p[tempindex].at;
                p[tempindex].wt = p[tempindex].tt- p[tempindex].bt;
                p[k].status = 2;
                k++;
                num++;
            } else if (p[tempindex].remaining > t)
            {
                d[k].ct = clock + t;
                clock = d[k].ct;
                p[tempindex].remaining =  p[tempindex].remaining-t;
                k++;

                for (int j = 0; j < n; j++)
                {
                    if (p[j].status == 0 && p[j].at <= clock)
                    {
                        enqueue(j);
                        p[j].status = 1;
                    }
                    enqueue(tempindex);
                }
                
            }
            
            
        } else
            clock++;
        
    }

    printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
    for (int i = 0; i < n; i++) {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].ct, p[i].wt, p[i].tt);
        awt += p[i].wt;
        att += p[i].tt;
    }


    
    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------------\n\t");

    for (int i = 0; i < k; i++) {
        printf("|%s\t", d[i].name);
    }

    printf(" |\n\t--------------------------------------------------------------------------\n\t");
    
    for (int i = 0; i < k; i++) {
        printf("%d\t", d[i].st);
    }

    printf("%d\t", d[k - 1].ct);
    printf("\n\nAVERAGE WAITING TIME : %f", (awt / n));
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (att / n));


    
    
}