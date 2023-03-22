#include<stdio.h>
int main(){
    int n=0,i;
    scanf("%d",&n);
    for( i=0;n!=0;i++){
        printf("%d",n%10);
         n=n/10;
    }
    printf("\n");
    printf("%d",i);
}