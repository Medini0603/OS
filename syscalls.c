#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#define size 30
void main()
{
    int f=open("13file.c",O_RDWR);
    char buffer[size];
    int n;
    if(f==-1)
    {
        printf("File does not exist\n");
        exit(0);
    }
    n=read(f,buffer,10);
    printf("First 10 char are read\n");
    write(1,buffer,n);
    printf("\n");
    
    lseek(f,10,SEEK_CUR);
    printf("Skipping 10 charactes from current position\n");
    n=read(f,buffer,10);
    write(1,buffer,n);
    printf("\n");
    
    lseek(f,-10,SEEK_CUR);
     printf("Going back 10 charactes from current position\n");
     n=read(f,buffer,10);
     write(1,buffer,n);
     printf("\n");
     
     lseek(f,10,SEEK_SET);
     printf("Going to 10 characters in file\n");
     n=read(f,buffer,10);
     write(1,buffer,n);
     
      lseek(f,-5,SEEK_END);
     printf("Going to last 5th characters in file\n");
     n=read(f,buffer,10);
     write(1,buffer,n);
}






