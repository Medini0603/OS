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
   int completed=0;
   int ganttemp[3*n];
   int gantpid[3*n];
   int t=p[0].at;
   //ganttemp[0]=t;
   int m=0,min=0;
   int j=-1;
   int gl=0;
    gantpid[0]=-1;
   
   while(completed!=n)
   {
        m=999;
        for(int i=0;i<n;i++)
        {
            if(p[i].at>t || p[i].bt==0)continue;
            if(p[i].bt<m)
            {
                m=p[i].bt;
                min=i;
            }
        }
        p[min].bt-=1;
        t++;
        p[min].ct=t;
        
        if(p[min].bt==0)completed++;
        
        //Gantt code
        if(gantpid[j]!=p[min].pid)
        {
            j++;
            gl++;
        }
        
        gantpid[j]=p[min].pid;
        ganttemp[j]=p[min].ct;
     }
     
     printf("\n------------------------------------------------------------------------------------------------------\n");
     printf("%d ",p[0].at);
     for(int i=0;i<gl;i++)
        printf("P%d\t",gantpid[i]);
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<gl;i++)
        printf("  \t%d",ganttemp[i]);
}

void turnaroundtime(pro p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-temp[i];
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,temp[i],p[i].ct,p[i].tt,p[i].wt);
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














