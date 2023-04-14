#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
    pid_t my,parent,child;
    child=fork();
    
    if(child<0)
    {
        printf("Fork failed\n");
        exit(0);
    }
    
    else if(child==0)
    {
        printf("[CHILD] This is child process\n");
        my=getpid();
        parent =getppid();
         printf("[CHILD] My pid is %d\n",my);
          printf("[CHILD] Parents pid is %d\n",parent);
          printf("[CHILD]Child exiting\n");
          exit(0);
    }
    
    else
    {
         printf("[Parent] This is parent process\n");
        my=getpid();
        parent =getppid();
         printf("[PArent] My pid is %d\n",my);
          printf("[Parent] Parents pid is %d\n",parent);
          printf("Parent sleeping for 10 seconds\n");
          sleep(10);
          printf("[Parent] child pid is %d it has ended but its entry is in process table therefore it is a Zombie process now :-((\n",child);
         
    }
}
