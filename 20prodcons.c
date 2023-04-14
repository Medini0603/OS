#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include<pthread.h>
#include<semaphore.h>

#define max 5
#define buffersize 5

sem_t empty,full;
int in=0,out=0,buffer[buffersize];
pthread_mutex_t mutex;

void *producer(void *pro)
{
    int item;
    
    srand(time(NULL));
    for(int i=0;i<max;i++)
    {
    item=rand()%100;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    buffer[in]=item;
    printf("Producer %d added %d to buffer at %d\n",*((int*)pro),buffer[in],in);
    in=(in+1)%buffersize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    }
}

void *consumer(void *con)
{
    for(int i=0;i<max;i++)
    {
    int item;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    item=buffer[out];
    printf("Consumer %d consumed %d from buffer at %d\n",*((int*)con),buffer[out],out);
    out=(out+1)%buffersize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    }
}

void main()
{
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty,0,buffersize);
    sem_init(&full,0,0);
    
    int a[5]={1,2,3,4,5};
    
    for(int i=0;i<5;i++)
    {
        pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        pthread_join(pro[i],NULL);
    }
    
    for(int i=0;i<5;i++)
    {
        pthread_join(con[i],NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}







