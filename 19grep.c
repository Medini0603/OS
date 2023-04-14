#include<stdio.h>
#include<string.h>

void main()
{
    char fn[10],pat[10],temp[200];
    FILE *f;
    printf("Enter file name\n");
    scanf("%s",fn);
    printf("Enter pattern to be searched\n");
    scanf("%s",pat);
    
    f=fopen(fn,"r");
    
    while(!feof(f))
    {
        fgets(temp,100,f);
        if(strstr(temp,pat))
            printf("%s",temp);
    }
    fclose(f);
}
