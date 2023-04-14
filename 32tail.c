#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("Invalid\n");
        exit(0);
        
    }
    
    FILE *f=fopen(argv[1],"r");
    char temp[1000];
    int cnt=0;
    while(!feof(f))
    {
        fgets(temp,1000,f);
        cnt++;
    }
    int i;
    fclose(f);
    f=fopen(argv[1],"r");
    for(int i=1;i<cnt;i++)
    {
        fgets(temp,1000,f);
        if(i>=(cnt-10))
            printf("%s",temp);
    }
    fclose(f);
}
