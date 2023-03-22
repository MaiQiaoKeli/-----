#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[1001],temp[1001];
        scanf("%s",s);
        int l=strlen(s),flag=0,i=0,j=l,begin=0,end=0,max=0;
  //      while(i<=j){
            for(i=0;i<l;i++){
                begin=i; 
                j=l;       //i不动，j动
                end=j;
                for(;end>=begin;){

                    if(s[begin]==s[end]){
                        begin++,end--;
                        flag=1;
                    }
                    else j--,begin=i,end=j,flag=0;
                }              //j动，依次遍历

                if(flag==1&&(j-i+1)>max){
                    strncpy(temp,s+i,j-i+1);
                    max=j-i+1;
                }
            }

            printf("%.*s\n",max,temp);

 //       }


    }
}