#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define size 30

void main()
{
    int fd;
    int n;
    char buffer[size];
    fd=open("13file.c",O_RDWR);
    printf("File descriptor %d\n",fd);
    if(fd==-1)
    {
        printf("Couldnt open file\n");
        exit(0);
    }
    
    printf("Reading first 10 characters\n");
     n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("\n");
    
    printf("Skipping 5 characters from the current position\n");
    lseek(fd,5,SEEK_CUR);
     n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("\n");
    
    printf("Going to 5th last character of file\n");
    lseek(fd,-5,SEEK_END);
     n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("\n");
    
     printf("Going to 3rd character of file\n");
    lseek(fd,3,SEEK_SET);
     n=read(fd,buffer,10);
    write(1,buffer,n);
    printf("\n");
}





