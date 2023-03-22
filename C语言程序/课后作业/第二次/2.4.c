#include<stdio.h>
int kongge=0;
int letter=0;
int suzi=0;
 void find_kongge(char s);
 void find_letter(char s);
 void find_suzi(char s);
int main(){
    char s;
    int i;
    for(i=0;(s=getchar())!='\n';i++){
        find_kongge(s);
        find_letter(s);
        find_suzi(s);
}
    printf("空格有%d个\n",kongge);
    printf("字母有%d个\n",letter);
    printf("数字有%d个\n",suzi);
    printf("其他字符有%d个\n",i-kongge-letter-suzi);
}
void find_kongge(char s){
        if(s==' '){
            kongge++;
        }
}

void find_letter(char s){
    if((s<='z'&&s>='a')||(s<='Z'&&s>='A'))
       letter++;
}
 
void find_suzi(char s){
    if(s>='0'&&s<='9')
       suzi++;
}

