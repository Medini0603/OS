#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>

#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>

void main(int argc,char *argv[])
{
    printf("Child \n");
    int shmid;
    void *ptr;
    int SIZE =4096;
    shmid=shmget((key_t)0012,SIZE,0666|IPC_CREAT);
    ptr=shmat(shmid,NULL,0666);
    
    int i=atoi(argv[1]);
    int k=1;
    int cnt=1;
    while(cnt!=i)
    {
        sprintf(ptr,"%d",k);
        printf("%d ",k);
        k+=2;
        cnt++;
        ptr+=strlen(ptr);
    }
    shmdt("OS");
}


