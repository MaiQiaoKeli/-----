#include<stdio.h>
# include <string.h>
int main(void)
{
    /*********Begin*********/
    char str1[100],str2[100],str3[200];
     int n,t1,t2,i;
	 gets(str1);
	 gets(str2);
	 scanf("%d",&n);
     t1=strlen(str1);//算出字符串的长度
	 t2=strlen(str2);
    for( i=0;i<t1+t2;i++)
	{
        if(i<n) str3[i]=str1[i];// 指定位置之前的字符串，由str1字符串填充
		else if(i<n+t2) str3[i]=str2[i-n];//指定位置之后的字符串，由str2字符串填充
		else str3[i]=str1[i-t2];//插入str2以后剩下的位置由str1字符串填充
	}
	str3[i]='\0';//字符串必须有'\0'结尾
	puts(str3);
    /*********End**********/
    return 0;
}
