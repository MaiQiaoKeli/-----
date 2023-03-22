#include<stdio.h>

float max(float*,int);
float min(float*,int);

int main(){
   int n,t;
   scanf("%d",&n);
   while(n--){
    float num=0;
        scanf("%d",&t);
        float a[t];
        for(int i=0;i<t;i++){
           scanf("%f",&a[i]);
           num+=a[i];
          
        }
     
        num=num-max(a,t)-min(a,t);
        printf("%.2f\n",num/(t-2));
    }
    return 0;
}

float max(float a[], int n){
   
   float max= a[0];
   
   for(int i=0;i<n;i++){
      if(a[i] > max)
         max = a[i];
   }

   return max;
}

float min(float a[],int n){
    float maximum=a[0];
    for(int i=0;i<n;i++){
        if(maximum>a[i])
        maximum=a[i];
    }
    return maximum;
}