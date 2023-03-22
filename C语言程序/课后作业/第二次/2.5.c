#include<stdio.h>

int fib(int);

int main(){
    int times;
    scanf("%d",&times);
    for(int i=1;i<times;i++){
        printf("%d ",fib(i));
    }
}

int fib(int s){
    if(s==1||s==2)
    return 1;
    else 
    return fib(s-1)+fib(s-2);
    
}