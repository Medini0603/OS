#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/stat.h>

void main(int argc,char *argv[])
{
    if(argc<3)
    {
        printf("Insufficient arguments passed\n");
        exit(0);
    }
    int i;
    sscanf(argv[1],"%d",&i);
    if(i<=0)
    {
        printf("Invalid arguments passed\n");
        exit(0);
    }
    
    void *ptr;
    int shmid;
    pid_t child; 
    int SIZE =4096;
    
    
    child=fork();
    if(child==0)
    {
        execlp("./prime2","prime",argv[1],argv[2],NULL);
    }
    else
    {
    wait(NULL);
    printf("Child completed parent completing\n");
    shmid=shm_open("OS",O_RDONLY,0666);
    ftruncate(shmid,SIZE);
    ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shmid,0);
    printf("Parent printing\n");
    printf("%s",(char*)ptr);
    shm_unlink("OS");
     }
}





