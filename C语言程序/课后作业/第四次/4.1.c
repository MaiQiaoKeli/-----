#include<stdio.h>
#include<string.h>
void main()
{
int i,j,la,lb,num=0;
char c,a[120],b[4500];
while((c=getchar())!='\n') 
    a[num++]=c;
    a[num]='\0';
    num=0;
while((c=getchar())!='\n') 
    b[num++]=c;b[num]='\0';
    la=strlen(a);
    lb=strlen(b);
    for(i=0;(lb-i)>=la;i++)
{   if(b[i]==a[0])
{   for(j=0;j<la;j++)
    if(b[i+j]!=a[j]) break;
    if(j==la) {printf("%d\n",i+1);break;}
}
}
}