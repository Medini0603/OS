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
    int n1,n2;
    
    int SIZE=4096;
    
    int i=atoi(argv[1]);
    
    printf("CHILD\n");
     
    shmid=shmget((key_t)1122,SIZE,0666|IPC_CREAT);
     
    ptr=shmat(shmid,NULL,0666);
   
    n1=0,n2=1;
    sprintf(ptr,"%d ",n1);
    ptr+=strlen(ptr);
    printf("%d ",n1);
    sprintf(ptr,"%d ",n2);
    ptr+=strlen(ptr);
    printf("%d ",n2);
    
    int k=2;
    while(k!=i)
    {
        int n3=n2+n1;
        sprintf(ptr,"%d ",n3);
        printf("%d ",n3);
        ptr+=strlen(ptr);
        n1=n2;
        n2=n3;
         k++;
    }
    shmdt("OS");
}


