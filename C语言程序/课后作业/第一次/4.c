#include<stdio.h>
long long s(int n){
    long long sum=1;
    for(int i=1;i<=n;i++){
    sum=sum*i;
    }
    return sum;
    }
int main(){
    int n,m=0;
    long long q,p=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       p+=s(i);
    }
    printf("%lld",p);
}