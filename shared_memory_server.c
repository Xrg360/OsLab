#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)3000,27,00666|IPC_CREAT);
    printf("key = %d",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("process attached at %d",shmid);
    printf("enter the data to be written to the memory");
    read(0,buff,100);
    strcpy(shared_memory,buff);
}