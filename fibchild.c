#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/shm.h>

void main(int argc,char*argv[])
{ 
     int shmid;
    int SIZE=4096;
    void *ptr;
    int i=atoi(argv[1]);
    int n1=0,n2=1;
    shmid=shmget((key_t)1122,SIZE,0666|IPC_CREAT);
    ptr=shmat(shmid,NULL,0666);
    
    printf("Child printing\n");
    printf("%d ",n1);
    sprintf(ptr,"%d ",n1);
    ptr+=strlen(ptr);
    
     printf("%d ",n2);
    sprintf(ptr,"%d ",n2);
    ptr+=strlen(ptr);
    
    int k=1;
    while(k!=i)
    {
        int n3=n1+n2;
        printf("%d ",n3);
        sprintf(ptr,"%d ",n3);
        ptr+=strlen(ptr);
        n1=n2;
        n2=n3;
        k++;
    }
}


