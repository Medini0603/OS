//To demonstrate fork() system call

#include<stdio.h>
#include <unistd.h>
int main()
{
  printf("Before fork\n");//P0
  fork(); //P1, 2^1=2 (p0,p1)
  fork(); // P2,P3,  2^2=4  (p0,p1,p2,p3)
  fork(); // P4,P5,P6,P7, 2^3=8 (p0,p1,p2,p3,p4,p5,p6,p7)
  printf("After fork\n");
  return(0);
}

//To demonstrate fork() system call

#include <unistd.h>
#include <stdio.h>
int main() 
{
printf("Before fork\n");
fork(); //P1 (p0,p1)
printf("After first fork\n"); //printed 2 times
fork(); //P2,P3 (p0,p1,p2,p3)
printf("After second fork\n"); //printed 4 times
fork(); //P4,P5,P6,P7 (p0,p1,p2,p3,p4,p5,p6,p7)
printf("After third fork\n"); //printed 8 times
return 0;
}


//TO DEMONSTRATE EXIT(),GETPID(),GETPPID(),WAIT(),SLEEP(),EXECLP()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() 
{
pid_t child_pid,my_pid,parent_pid,wid;
int i = 10;
child_pid = fork();
if (child_pid < 0) 
{
printf("Fork failed. Exiting!\n");
exit(0);
}
if (child_pid == 0) 
{
// Child process
  //printf("[CHILD] Before using exit syscall\n");
  //exit(0);
  printf("[CHILD] This is the child process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[CHILD] My pid is %d\n", my_pid);
  printf("[CHILD] My parent's pid is %d\n", parent_pid);
  printf("[CHILD] i= %d\n",--i);
  printf("[CHILD] Child process going to load another program using execlp syscall\n");
  execlp("/bin/pwd", "pwd", NULL);
} 
else 
{
  // Parent process
    printf("[PARENT] This is the parent process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[PARENT] My pid is %d\n", my_pid);
  printf("[PARENT] Waiting for child to terminate\n");
  wid=wait(NULL);
  printf("[PARENT] Resuming after the termination of %d\n", wid);
  printf("[PARENT] My parent's pid is %d\n", parent_pid);
  printf("[PARENT] My child's pid is %d\n", child_pid);
   printf("[PARENT] i= %d\n",++i);
}
return 0;
}
