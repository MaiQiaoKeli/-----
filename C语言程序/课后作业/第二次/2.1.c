#include<stdio.h>
int main(){
    int year;
    scanf("%d",&year);
    if(year%4==0){
        if(year<100||(year>100&&year%100!=0))
           printf("普通闰年");
        else printf("不是闰年");
    }
    else if(year%400==0&&year>=400){
        printf("特殊闰年");
    }
    else printf("不是闰年");
        return 0;
}