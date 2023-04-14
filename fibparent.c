#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/shm.h>

void main(int argc,char*argv[])
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        exit(0);
    }
    
    int i;
    sscanf(argv[1],"%d",&i);
    if(i<0)
    {
         printf("Invalid arguments\n");
        exit(0);
    }
    
    pid_t child;
    int shmid;
    int SIZE=4096;
    void *ptr;
    child=fork();
    if(child==0)
    {
        execlp("./fibo2","fibo",argv[1],NULL);
    }
    else
    {
        wait(NULL);
        printf("PARENT:child completed\n");
        shmid=shmget((key_t)1122,SIZE,0666|IPC_CREAT);
        ptr=shmat(shmid,NULL,0666);
        printf("PArent printing\n");
        printf("%s",(char*)ptr);
        shmctl(shmid,IPC_RMID,NULL);
    }
}


