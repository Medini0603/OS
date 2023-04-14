#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

void main()
{
    pid_t child,my,parent;
    child=fork();
    
    if(child==0)
    {
        printf("[CHILD] this is child process");
        my=getpid();
        parent=getppid();
        printf("[CHILD] my pid is %d\n",my);
        printf("[CHILD] my parents pid is %d\n",parent);
        printf("CHILD exiting");
        exit(0);
    }
    
    if(child>0)
    {
        printf("[PARENT] this is parent process");
        my=getpid();
        parent=getppid();
        printf("[Parent] my pid is %d\n",my);
        printf("[Parent] my parents pid is %d\n",parent);
        printf("\nParent sleeping");
        sleep(8);
        printf("\nChild %d has ended its entry is in process table so it is a zombie process\n",child);
    }

}





