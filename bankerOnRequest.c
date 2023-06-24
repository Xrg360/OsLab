//write me the code for the bankers algorith with a process requesting the resource

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//global variables
int n, m, i, j, k, available[10], allocation[10][10], max[10][10], need[10][10], work[10], finish[10], safe[10], count = 0;

//function prototypes
void input();
void display();
void bankers();

int main()
{
    input();
    display();
    request();
    bankers();
    return 0;
}

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);
    printf("Enter the allocation matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    printf("Enter the max matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void request()
{
    int process, request[m];
    printf("Enter the process requesting resources: ");
    scanf("%d", &process);
    printf("Enter the request: ");
    for (i = 0; i < m; i++)
        scanf("%d", &request[i]);
    for (i = 0; i < m; i++)
    {
        if (request[i] > need[process][i] || request[i] > available[i])
        {
            printf("Allocation not possible\n");
            return;
        }
    }
    for (i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
    bankers();
}

void display()
{
    printf("Allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }
    printf("Max matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }
    printf("Need matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
}

void bankers()
{
    //initializing finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;
    //initializing work array
    for (i = 0; i < m; i++)
        work[i] = available[i];
    //initializing safe array
    for (i = 0; i < n; i++)
        safe[i] = -1;
    //checking for safe sequence
    while (count < n)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m)
                {
                    for (k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }
    //printing safe sequence
    printf("Safe sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", safe[i]);
    printf("\n");
}
