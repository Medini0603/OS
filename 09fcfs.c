#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int pid,bt,at,tt,wt,ct;
}pro;
int temp[10];
void sortat(pro p[],int n)
{
   
    for(int j=0;j<n-1;j++)
    {
        for(int i=0;i<n-j-1;i++)
        {
            if(p[i].at>p[i+1].at)
            {
                pro *p1=&p[i];
                pro *p2=&p[i+1];
                pro t=*p1;
                *p1=*p2;
                *p2=t;
                
                int temporary =temp[i];
                temp[i]=temp[i+1];
                temp[i+1]=temporary;
            }
        }
    }
    
}

void schedule(pro p[],int n)
{
    int t=p[0].at;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("%d |",t);
    for(int i=0;i<n;i++)
    {
        t+=p[i].bt;
        p[i].ct=t;
        
        printf("\tP%d %d\t|",p[i].pid,p[i].bt);
    }
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("0");
    for(int i=0;i<n;i++)
    {
        printf("\t    \t%d",p[i].ct);
    }
}

void turnaroundtime(pro p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
    }
}

void avgtime(pro p[],int n)
{
    printf("Gantt chart\n");
    sortat(p,n);
    schedule(p,n);
    turnaroundtime(p,n);
    printf("\nPID\tat\tbt\tct\ttt\twt\n");
    int tottt=0,totwt=0;
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        tottt+=p[i].tt;
        totwt+=p[i].wt;
    }
    printf("Avg tt = %f",(float)tottt/(float)n);
    printf("Avg wt = %f",(float)totwt/(float)n);
}
void main()
{
    int n;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    pro p[n];
    
    printf("Enter pid,at,bt of\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d\n",i+1);
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
        temp[i]=p[i].bt;
    }
    
    avgtime(p,n);
}














