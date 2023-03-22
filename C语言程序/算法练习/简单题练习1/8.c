#include<stdio.h>

int fib(int i,int a,int b){
    if(i==0) return a;
    if(i==1) return b;
    else return fib(i-1,b,a+b);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,num,temp;
        scanf("%d%d%d",&a,&b,&num);
        
        while(num--){
            int n,i=0;
            scanf("%d",&n);
            
            while(1){
            if(fib(i,a,b)%3==0)
                break;
            else i++;    
            }


            if((n-i)%4==0&&i<=n)
            printf("Yes\n");
            else if(a%3==0&&b%3==0)
            printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
       
    }
}