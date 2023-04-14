#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
void main()
{
    char fn[10],pat[20];
    printf("Enter file name\n");
    scanf("%s",fn);
    printf("Enter pattern to be searched\n");
    scanf("%s",pat);
    
    FILE* f=fopen(fn,"r");
    char temp[200];
    while(!feof(f))
    {
        fgets(temp,200,f);
        if(strstr(temp,pat))
        {
            printf("%s\n",temp);
        }
    }
    fclose(f);
}
