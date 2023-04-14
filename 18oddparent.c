#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/stat.h>

void main(int argc,char *argv[])
{
    int shmid;
    void *ptr;
    pid_t pid;
    int n;
    
    int SIZE=4096;
    
    if(argc<=1)
    {
        printf("Arguments not passed\n");
        exit(0);
    }
    
    else
    {
        sscanf(argv[1],"%d",&n);
        
        if(n<1)
        {
            printf("Invalid input\n");
            exit(0);
        }
    }
    
    pid=fork();
    if(pid==0)
    {
        execlp("./odd","odd",argv[1],NULL);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("\nParent : child completed\n");
        shmid=shmget((key_t)1122,SIZE,0666|IPC_CREAT);
        ptr=shmat(shmid,NULL,0666);
      
        printf("%s",(char*)ptr);
        shmctl(shmid,IPC_RMID,NULL);
    }
}


