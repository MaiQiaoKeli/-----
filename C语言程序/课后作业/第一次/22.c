#include<stdio.h>
int main(){
    int a,b;
    long int count;
    scanf("%d %d",&a,&b);
    
    getchar();
    int A[a],B[b];
    for(int i=0;i<a;i++){
        A[i]=getchar();
    }
    getchar();
     for(int i=0;i<a;i++){
        B[i]=getchar();
    }

    for(int i=0;i<a;i++)
    {
         for(int j=0;j<b;j++)
         {
            if(A[i]>B[j])
            count++;
         }
    }
    printf("%ld",count);  
}