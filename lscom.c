#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>

void main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *dir;
    
    if(argc<2)
    {
        printf("Insufficient arguents passed\n");
        exit(0);
    }
    
    if((dp=opendir(argv[1]))==NULL)
    {
        printf("cant open directory does not exists\n");
        exit(0);
    }
    
    while((dir=readdir(dp))!=NULL)
    {
        printf("%s\n",dir->d_name);
    }
    closedir(dp);
}


