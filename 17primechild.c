#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/mman.h>

void main(int argc, char * argv[])
{
    printf("Child\n");
    int SIZE=4096;
    int shmid=shm_open("OS",O_CREAT|O_RDWR,0666);
    ftruncate(shmid,SIZE);
    void *ptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmid,0);
    
    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);
    
    for(int i=n1+1;i<n2;i++)
    {
        int flag=0;
        for(int j=2;j<=(i/2);j++)
        {
            if(i%j==0)
            {flag=1;break;}
        }
        if(flag==0)
        {
            sprintf(ptr,"%d ",i);
            ptr+=strlen(ptr);
            printf("%d ",i);
        }
    }
}
