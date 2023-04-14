#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>

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
        execlp("./fib","fib",argv[1],NULL);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("\nParent : child completed\n");
        
        shmid=shm_open("OS",O_RDONLY,0666);
        ftruncate(shmid,SIZE);
        ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shmid,0);
        printf("PArent printing\n");
        printf("%s",(char*)ptr);
        shm_unlink("OS");
    }
}


