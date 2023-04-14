#include<stdio.h>
#include<stdlib.h>

typedef struct process{
int pid,pt,bt,ct,tt,wt,flag;
}pro;

int temp[10];
void turnaroundtime(pro p[],int n)
{
for(int i=0;i<n;i++)
p[i].tt=p[i].ct;
}

void waittime(pro p[],int n)
{
for(int i=0;i<n;i++)
p[i].wt=p[i].tt-temp[i];
}

void sortpt(pro p[],int n)
{
pro t,*p1,*p2;

for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(p[j].pt>p[j+1].pt)
{
p1=&p[j];
p2=&p[j+1];
t=*p1;
*p1=*p2;
*p2=t;
int a=temp[j];
temp[j]=temp[j+1];
temp[j+1]=a;
}
}
}
}

void schedule(pro p[],int n,int quantum)
{
int pri=p[0].pt;
int time=0;
int wait[n];
int r=-1;
int f=0;
int completed=0;
int cnt;
while(completed!=n)
{
cnt=0;
pri=p[completed].pt;
for(int i=0;i<n;i++)
{
if(p[i].pt==pri && p[i].flag==0)
{
r=(r+1)%n;
wait[r]=i;
p[i].flag=1;
cnt++;
}
}

int var=0;
while(var!=cnt)
{
int cur=wait[f];
        f=(f+1)%n;
        if (p[cur].bt >= quantum)
        {
            p[cur].bt = p[cur].bt - quantum;
            time += quantum;
        }
        else
        {
            time += p[cur].bt;
            p[cur].bt=0;
        }
        p[cur].ct = time;

        if (p[cur].bt > 0)
        {
            r=(r+1)%n;
            wait[r]=cur;
        }
        else {completed++;var++;}
    }
}
}



void avgtime(pro p[],int n,int quantum)
{

schedule(p,n,quantum);
turnaroundtime(p,n);
waittime(p,n);

printf("\npid\tat\tbt\tct\ttt\twt\n");
int tott=0,totwt=0;

for(int i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].pt,temp[i],p[i].ct,p[i].tt,p[i].wt);
tott+=p[i].tt;
totwt+=p[i].wt;
}

printf("Avg tt = %f\n",(float)tott/(float)n);
printf("Avg wt = %f\n",(float)totwt/(float)n);
}

void main()
{
pro p[10];
int n,quantum;
printf("Enter number of processes\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("Enter pid,priority and bt of process %d\n",i+1);
scanf("%d %d %d",&p[i].pid,&p[i].pt,&p[i].bt);
temp[i]=p[i].bt;
p[i].ct=0;
p[i].flag=0;
}

printf("Enter quantum\n");
scanf("%d",&quantum);
sortpt(p,n);
avgtime(p,n,quantum);
}
