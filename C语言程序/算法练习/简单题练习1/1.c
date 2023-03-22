#include<stdio.h>
int main(){
    int n,a,b,c,d;
   
    scanf("%d",&n);
    int num[n];
   for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
   //     d=a>b?a:b;
        if(a>b){
            if(a>c){
                if(b>c){
                   num[i]=b;
                }
                else num[i]=c;
            }
            else num[i]=a;
    }
        if(a<b){
            if(b>c){
                if(a>c){
                    num[i]=a;
                }
                else num[i]=c;
            }
            else num[i]=b;
        }
        if(a=b=c){
            num[i]=a;
        }
        if(a=b){
            if(a<c) num[i]=c;
        }
        else num[i]=a;
      
   }
    for(int i=0;i<n;i++){
        printf("%d\n",num[i]);
    }
}