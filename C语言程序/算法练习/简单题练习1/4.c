#include<stdio.h>
int main(){
    int n,t,k;
    scanf("%d",&n);
  
    while(n--){
        int light[1001]={0};
        scanf("%d",&t);//灯的数目
        scanf("%d",&k);//人的数目
        for(int i=1;i<=t;i++){
            for(int j=1;j<=k;j++){
                if(i%j==0){
                    light[i]++;
                }
            }
        }
        for(int i=1;i<=t;i++){
            if(light[i]%2!=0)
            printf("%d ",i);
        }
        puts("\n");
    }
}