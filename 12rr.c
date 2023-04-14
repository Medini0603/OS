#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int pid,bt,at,tt,wt,ct,flag;
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

void schedule(pro p[],int n,int quantum)
{
  int time=p[0].at;
  int completed=0;
  int wait[n];
  int f=0,r=-1,cnt=0;
  printf("\n-------------------------------------------------------------------------------------------------------\n");
  printf("%d ",time);
  r=(r+1)%n;
  wait[r]=0;
  cnt++;
  p[0].flag=1;
  int ganttemp[n*3];
  int len=0;
  while(completed!=n)
  {
    int cur=wait[f];
    f=(f+1)%n;
    cnt--;
    
    if(p[cur].bt>quantum)
    {
        p[cur].bt-=quantum;
        time+=quantum;
        printf("P%d %d\t|",p[cur].pid,quantum);
    }
    else
    {
        time+=p[cur].bt;
         printf("P%d %d\t|",p[cur].pid,p[cur].bt);
        p[cur].bt=0;
    }
    
    p[cur].ct=time;
    ganttemp[len++]=p[cur].ct;
    
    for(int i=0;i<n ;i++)
    {
        if(p[i].at>time)break;
        if(p[i].flag==1 || p[i].bt==0 || i==cur)continue;
        
        r=(r+1)%n;
        wait[r]=i;
        cnt++;
        p[i].flag=1;
    }
    if(p[cur].bt!=0)
    {
        r=(r+1)%n;
        wait[r]=cur;
        cnt++;
    }
    else completed++;
  }
  
  printf("\n--------------------------------------------------------------------------------------------------------\n");
  for(int j=0;j<len;j++)
  {
    printf("    \t%d",ganttemp[j]);
  }
}

void turnaroundtime(pro p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-temp[i];
    }
}

void avgtime(pro p[],int n,int quantum)
{
    printf("Gantt chart\n");
    sortat(p,n);
    schedule(p,n,quantum);
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
        p[i].flag=0;
    }
    int quantum;
    printf("Enter quantum\n");
    scanf("%d",&quantum);
    avgtime(p,n,quantum);
}














