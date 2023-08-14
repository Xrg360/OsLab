#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

int memory[MAX];
int size[MAX];
int n;

void initialize()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        memory[i] = 0;
        size[i] = 0;
    }
}

void display()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (memory[i] == 0)
            printf("Free\t%d\n", size[i]);
        else
            printf("Occupied\t%d\n", size[i]);
    }
}

void firstfit(int process_size)
{
    int i, j, flag = 0;
    for (i = 0; i < MAX; i++)
    {
        if (memory[i] == 0 && size[i] >= process_size)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Starting address of allocated memory: %d\n", i);
        printf("Size of allocated memory: %d\n", process_size);
        printf("External fragmentation: %d\n", size[i] - process_size);
        memory[i] = 1;
        size[i] = process_size;
    }
    else
        printf("No memory allocated\n");
}

void bestfit(int process_size)
{
    int i, j, flag = 0, min = 9999, index = -1;
    for (i = 0; i < MAX; i++)
    {
        if (memory[i] == 0 && size[i] >= process_size && size[i] < min)
        {
            flag = 1;
            min = size[i];
            index = i;
        }
    }
    if (flag == 1)
    {
        printf("Starting address of allocated memory: %d\n", index);
        printf("Size of allocated memory: %d\n", process_size);
        printf("External fragmentation: %d\n", size[index] - process_size);
        memory[index] = 1;
        size[index] = process_size;
    }
    else
        printf("No memory allocated\n");
}

void worstfit(int process_size)
{
    int i, j, flag = 0, max = -1, index = -1;
    for (i = 0; i < MAX; i++)
    {
        if (memory[i] == 0 && size[i] >= process_size && size[i] > max)
        {
            flag = 1;
            max = size[i];
            index = i;
        }
    }
    if (flag == 1)
    {
        printf("Starting address of allocated memory: %d\n", index);
        printf("Size of allocated memory: %d\n", process_size);
        printf("External fragmentation: %d\n", size[index] - process_size);
        memory[index] = 1;
        size[index] = process_size;
    }
    else
        printf("No memory allocated\n");
}

int main()
{
    int i, j, choice, process_size;
    initialize();
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the size of each memory block: ");
    for (i = 0; i < n; i++)
        scanf("%d", &size[i]);
    while (1)
    {
        printf("1. Display\n2. First fit\n3. Best fit\n4. Worst fit\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("Enter the size of the process: ");
            scanf("%d", &process_size);
            firstfit(process_size);
            break;
        case 3:
            printf("Enter the size of the process: ");
            scanf("%d", &process_size);
            bestfit(process_size);
            break;
        case 4:
            printf("Enter the size of the process: ");
            scanf("%d", &process_size);
            worstfit(process_size);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

