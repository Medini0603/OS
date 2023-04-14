#include<stdio.h>
#include<stdio.h>

typedef struct process
{
    int pid,at,bt,ct,tt,wt,flag;
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

void schedule(pro p[],int n,int quantum)
{
    int time=p[0].at;
    int completed=0;
    int ganttemp[3*n];
    printf("Gantt chart\n");
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("%d\t|",time);
    
    int wait[n];
    int f=0,r=0;
    wait[r]=0;
    p[0].flag=1;
    int gl=0;
    while(completed!=n)
    {
        int cur=wait[f];
        f=(f+1)%n;
        
        if(p[cur].bt>quantum)
        {
            printf("P%d\t|",p[cur].pid);
            p[cur].bt-=quantum;
            time+=quantum;
            p[cur].ct=time;
        }
        
        else
        {
            printf("P%d\t|",p[cur].pid);
            time+=p[cur].bt;
            p[cur].bt=0;
            p[cur].ct=time;
        }
        ganttemp[gl++]=p[cur].ct;
        
        for(int i=0;i<n;i++)
        {
            if(i==cur||p[i].at>time||p[i].flag==1||p[i].bt==0)continue;
            r=(r+1)%n;
            wait[r]=i;
            p[i].flag=1;
        }
        
        if(p[cur].bt!=0)
        {
            r=(r+1)%n;
            wait[r]=cur;
        }
        
        else completed++;
    }
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf(" \t ");
    for(int i=0;i<gl;i++)
    {
        printf("  \t %d",ganttemp[i]);
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
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,temp[i],p[i].ct,p[i].tt,p[i].wt);
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
    printf("Enter pid,at,bt of\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d\n",i+1);
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
        temp[i]=p[i].bt;
        p[i].flag=0;
    }
    printf("Enter quantum");
    int quantum;
    scanf("%d",&quantum);
    sortat(p,n);
    schedule(p,n,quantum);
    turnaroundtime(p,n);
    average(p,n);
}








