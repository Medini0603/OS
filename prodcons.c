#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#define max 5
#define BufferSize 5

int in=0,out=0,buffer[BufferSize];
sem_t full,empty;
pthread_mutex_t mutex;

void *producer(void *prono)
{
    srand(time(NULL));
    
    for(int i=0;i<max;i++)
    {
        int item=rand()%100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in]=item;
        printf("Producer %d adding %d item at %d\n",*((int *)prono),item,in);
        in=(in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *conno)
{
    for(int i=0;i<max;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        int item=buffer[out];
        printf("Consumer %d removed %d from %d\n",*((int *)conno),item,out);
        out=(out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

void main()
{
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,BufferSize);
    
    int a[5]={1,2,3,4,5};
    
    for(int i=0;i<5;i++)
        pthread_create(&pro[i],NULL,(void *)producer,(void*)&a[i]);
    
    for(int i=0;i<5;i++)
        pthread_create(&con[i],NULL,(void*)consumer,(void *)&a[i]);
        
    for(int i=0;i<5;i++)
        pthread_join(pro[i],NULL);
    
    for(int i=0;i<5;i++)
        pthread_join(con[i],NULL);
        
     pthread_mutex_destroy(&mutex);
     sem_destroy(&full);
     sem_destroy(&empty);
}



