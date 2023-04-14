#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/shm.h>

void main(int argc,char *argv[])
{
    int shmid;
    pid_t pid;
    int n1,n2;
    void *ptr;
    int SIZE=4096;
    
    if(argc<=2)
    {
        printf("Insuffiecient arguments passed\n");
        exit(0);
    }
    else
    {
        sscanf(argv[1],"%d",&n1);
        sscanf(argv[2],"%d",&n2);
    }
    
    pid =fork();
    if(pid==0)
    {
        execlp("./prime","prime",argv[1],argv[2],NULL);
    }
    
    else
    {
        wait(NULL);
        printf("PArent child completed\n");
        shmid=shm_open("OS",O_RDONLY,0666);
        ftruncate(shmid,SIZE);
        ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shmid,0);
        printf("PArent printing\n");
        printf("%s",(char*)ptr);
        shm_unlink("OS");
    }
}


