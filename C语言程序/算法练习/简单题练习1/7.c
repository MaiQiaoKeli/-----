#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,num=0;
        int day2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
        int day1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        scanf("%d%d%d",&a,&b,&c);
        if((a%4==0&&a%100!=0)||a%400==0){
            for(int i=0;i<b-1;i++){
                num+=day2[i];
            }
            printf("%d\n",num+c);
        }
        else {
            for(int i=0;i<b-1;i++){
                num+=day1[i];
            }
            printf("%d\n",num+c);
    }
}}