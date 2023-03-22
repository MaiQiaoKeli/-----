#include<stdio.h>
int main(){
    int n,a,b,c;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a>b){
            int temp=a;
            a=b;
            b=temp;
        }
        if(b>c){
            int temp=c;
                c=b;
                b=temp;
               
        }
        if(a>b){
            int temp=a;
            a=b;
            b=temp;
        }
    if(a==b&&b<c)
       num[i]=c;
    else num[i]=b;
}
   for(int i=0;i<n;i++){
    printf("%d\n",num[i]);
   }
   return 0;
}