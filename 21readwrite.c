#include<stdio.h>
#include<stdlib.h>

#include<pthread.h>
#include<semaphore.h>

pthread_mutex_t mutex;
sem_t wrt;
int rdcnt=0;
int cnt=1;

void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt=cnt*2;
    printf("Writer %d modified cnt to %d\n",*((int *)wno),cnt);
    sem_post(&wrt);
}

void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    rdcnt++;
    if(rdcnt==1)
    {
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d reading %d\n",*((int *)rno),cnt);
    pthread_mutex_lock(&mutex);
    rdcnt--;
    if(rdcnt==0)
        sem_post(&wrt);
   pthread_mutex_unlock(&mutex);
}

void main()
{
    pthread_t read[5],write[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&wrt,0,1);
    
    int a[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        pthread_create(&read[i],NULL,(void *)reader,(void *)&a[i]);
    }
    
     for(int i=0;i<5;i++)
    {
        pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        pthread_join(read[i],NULL);
    }
    
     for(int i=0;i<5;i++)
    {
        pthread_join(write[i],NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
}





