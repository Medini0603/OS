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
    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);
    int SIZE=4096;
    printf("Child printing\n");
    int shmid=shm_open("OS",O_RDWR|O_CREAT,0666);
    ftruncate(shmid,SIZE);
    void *ptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shmid,0);
    int flag;
    for(int i=n1+1;i<n2;i++)
    {
        flag=0;
        for(int j=2;j<=(i/2);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d ",i);
            sprintf(ptr,"%d ",i);
            ptr+=strlen(ptr);
        }
    }
   
}





