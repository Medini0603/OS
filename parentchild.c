#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
    pid_t child,my,parent,wid;
    child=fork();
    if(child<0)
    {
        printf("Fork failed \n");
        exit(0);
    }
    
    if(child==0)
    {
        printf("This is child");
        my=getpid();
        parent=getppid();
        printf("My pid %d\n",my);
        printf("Parent pid %d\n",parent);
        printf("Loading new process to child\n");
        execlp("/bin/pwd","pwd",NULL);
        
    }
    
    else
    {
        printf("This is parent");
        my=getpid();
        parent=getppid();
        printf("My pid %d\n",my);
        printf("Parent pid %d\n",parent);
        printf("Parent waiting for all its children to complete\n");
        wid=wait(NULL);
        printf("PArent resumed after termination of %d child\n",wid);
         printf("My pid %d\n",my);
        printf("Parent pid %d\n",parent);
    }
}



