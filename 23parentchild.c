#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>

void main()
{
    pid_t my,child,parent;
    child=fork();
    
    if(child<0)
    {
        printf("Fork failed \n");
        exit(0);
    }
    
    else if(child==0)
    {
        parent=getppid();
        my=getpid();
        printf("Child \n");
        printf("My pid is %d\n",my);
        printf("My parents pid is %d\n",parent);
        printf("Child is loading new program\n");
        execlp("/bin/pwd","pwd",NULL);
    }
    
    else
    {
        parent=getppid();
        my=getpid();
        printf("Parent \n");
        printf("My pid is %d\n",my);
        printf("My parents pid is %d\n",parent);
        printf("My childs pid is %d\n",child);
        printf("Waiting for all children to complte\n");
        pid_t wid = wait(NULL);
        printf("Parent resuming after %d teminated\n",wid);
        printf("My parents pid is %d\n",parent);
        printf("My childs pid is %d\n",child);
    }
}


