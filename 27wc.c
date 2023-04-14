#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char *argv[])
{
if(argc<2)
{
printf("Invalid arguments\n");
exit(1);
}

FILE *f;
f=fopen(argv[1],"r");
char temp;
int cnt=0;
while((temp=fgetc(f))!=EOF)
//if(temp=='\t')
cnt++;
fclose(f);
printf("%d",cnt);
}


