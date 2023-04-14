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
    printf("Gantt chart\n");
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("%d\t|",time);
    for(int i=0;i<n;i++)
    {
        time+=p[i].bt;
        p[i].ct=time;
        printf("P%d\t|",p[i].pid);
    }
    
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf(" \t ");
    for(int i=0;i<n;i++)
    {
        printf("  \t %d",p[i].ct);
    }
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








