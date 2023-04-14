#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>

#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/stat.h>

void main(int argc,char *argv[])
{
    int shmid;
    void *ptr;
    int SIZE=4096;
    int n;
    
    shmid=shm_open("OS",O_CREAT|O_RDWR,0666);
    ftruncate(shmid,SIZE);
    ptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmid,0);
    
    int i=atoi(argv[1]);
    printf("CHILD:\n");
    int n1=0,n2=1;
    sprintf(ptr,"%d",n1);
    ptr+=strlen(ptr);
    printf("%d\t",n1);
     sprintf(ptr,"%d",n2);
    ptr+=strlen(ptr);
    printf("%d\t",n2);
    int k=2;
    while(k!=i)
    {
        int n3=n1+n2;
        n1=n2;
        n2=n3;
        sprintf(ptr,"%d",n3);
        printf("%d\t",n3);
        ptr+=strlen(ptr);
        k++;
    }
    
}



