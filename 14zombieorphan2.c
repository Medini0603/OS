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
           printf("Child sleeping for 10 seconds\n");
          sleep(10);
           printf("[CHILD] My parent ended .So i am an orphan process adopted by init process\n");
    }
    
    else
    {
         printf("[Parent] This is parent process\n");
        my=getpid();
        parent =getppid();
         printf("[PArent] My pid is %d\n",my);
          printf("[Parent] Parents pid is %d\n",parent);
         printf("[Parent]Parent exiting\n");
          exit(0);
    }
}



