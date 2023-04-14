#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>

#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/wait.h>

void main(int argc,char *argv[])
{
     pid_t pid;
    int shmid;
    int SIZE= 4096;
    int n;
    void *ptr;
    
    if(argc<=1)
    {
        printf("Input not passed\n");
        exit(0);
    }
    
    else
    {
        sscanf(argv[1],"%d",&n);
        if(n<1)
        {
            printf("INvalid input\n");
            exit(0);
        }
    }
    
    pid=fork();
    if(pid==0)
    {
        execlp("./fib2","fib",argv[1],NULL);
    }
    
    else if(pid>0)
    {
        wait(NULL);
        printf("\nParent:child completed\n");
        
        shmid=shmget((key_t)0012,SIZE,0666|IPC_CREAT);
        ptr=shmat(shmid,NULL,0666);
        
        printf("Parent printing\n");
        printf("%s\n",(char *)ptr);
        shmctl(shmid,IPC_RMID,NULL);
    }
}





