#include<stdio.h>
#include<stdio.h>

typedef struct process
{
    int pid,at,bt,ct,tt,wt,pt;
}pro;
int temp[10];
void sortat(pro p[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                pro *p1=&p[j];
                pro *p2=&p[j+1];
                pro t=*p1;
                *p1=*p2;
                *p2=t;
                
                int tempo=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=tempo;
            }
        }
    }
}

void schedule(pro p[],int n)
{
    int time=p[0].at;
    int completed=0;
    int m,min;
    int gl=0;
    int gantpid[3*n];
    int ganttemp[3*n];
    int j=-1;
     printf("Gantt chart\n");
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    printf("%d\t|",time);
    while(completed!=n)
    {
        m=999;
        for(int i=0;i<n;i++)
        {
            if(p[i].at>time ||p[i].bt==0)continue;
            if(m>p[i].pt)
            {
                min=i;
                m=p[i].pt;
            }
        }
        
        time++;
        p[min].bt=p[min].bt-1;
        p[min].ct=time;
        
        if(p[min].bt==0)completed++;
        
        if(gantpid[j]!=p[min].pid)
        {
            j++;
            gl++;
        }
        
        gantpid[j]=p[min].pid;
        ganttemp[j]=p[min].ct;
    }
    
   for(int i=0;i<gl;i++)
        printf("P%d\t|",gantpid[i]);
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    printf(" \t ");
    for(int i=0;i<gl;i++)
        printf("  \t %d",ganttemp[i]);
    printf("\n");
}

void turnaroundtime(pro p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-temp[i];
    }
}

void average(pro p[],int n)
{
    int tott=0,totwt=0;
    printf("PID\tat\tbt\tpt\tct\ttt\twt\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tt,p[i].wt);
        tott+=p[i].tt;
        totwt+=p[i].wt;
    }
    
    printf("Average tt= %f\n",(float)tott/(float)n);
     printf("Average wt= %f\n",(float)totwt/(float)n);
}

void main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    pro p[n];
    printf("Enter pid,at,bt,pt of\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d\n",i+1);
        scanf("%d%d%d%d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pt);
        temp[i]=p[i].bt;
    }
    
    sortat(p,n);
    schedule(p,n);
    turnaroundtime(p,n);
    average(p,n);
}








