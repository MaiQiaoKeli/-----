#include<stdio.h>
int main(){
   int c;
   for(int a=100;a<1000;a++){
      int c=a/100;   //百位数；
      int b=(a-c*100)/10;   //十位数
      int d=a-c*100-b*10;//个位数
      if(a==c*c*c+b*b*b+d*d*d)
      printf("%d为水仙花数\n",a);
   }
}