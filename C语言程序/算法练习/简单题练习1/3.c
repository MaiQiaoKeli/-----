#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
   
    while(n--){
        int num1[10]={0},num2[10]={0};
        int n1,n2,flag=1;
        char s1[100],s2[100];
        scanf("%s",s1);
        scanf("%s",s2);
        n1=strlen(s1);
        n2=strlen(s2);
        
        for(int i=0;i<n1;i++){
            num1[s1[i]-'0']++;
        }
        for(int i=0;i<n2;i++){
            num2[s2[i]-'0']++;
        }
        
        for(int i=1;i<10;i++){
            if(num1[i]!=num2[i])
            flag=0;
        }
        
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}