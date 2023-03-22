#include<stdio.h>
int main(){
    char ch;
    printf("letter:");
    ch=getchar();
    getchar();
    switch(ch){
        case 'm':printf("monday");break;
        case 't':
                 printf("letter again:");
                 ch=getchar();
                 if(ch=='u')
                 printf("tuesday");
                 else if(ch=='h')
                 printf("thursday");
                 else printf("error!");break;
        case 'w':printf("wednesday");break;
        case 'f':printf("friday");break;
        case 's':printf("letter again:");
                 ch=getchar();
                 if(ch=='a')   
                 printf("saturday");break;
                 if(ch=='u')
                 printf("sunday");break;
        default:printf("error");break;

    }
    
}