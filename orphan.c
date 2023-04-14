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
        
        printf("\nChild sleeping");
        sleep(8);
        printf("\nMy parent has ended i am an orphan adapted by init process\n");
        
        
    }
    
    if(child>0)
    {
        printf("[PARENT] this is parent process");
        my=getpid();
        parent=getppid();
        printf("[Parent] my pid is %d\n",my);
        printf("[Parent] my parents pid is %d\n",parent);
        printf("Parent exiting");
        exit(0);
    }

}





