#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>

int main(){
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)3000,27,0666);
    printf("key = %d",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("process attached at %d",shared_memory);
    printf("the data to be read from the memory %s",(char *)shared_memory);
}