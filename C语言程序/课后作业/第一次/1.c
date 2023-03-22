#include<stdio.h>
#include<string.h>
int s(char*,char*);
int main(){
    int T=0;
    scanf("%d",&T);
    char* a[T*2];
    for(int t=0;t<T*2;t++){
        scanf("%s",a[t]);
    }
    for(int l=0;l<T;){
        s(a[l],a[l+1]);
        l=l+2;
    }

    printf("None");

}

int  s(char* a,char* b){
    for(int i=0;i<strlen(a);i++){
        for(int k=0;k<strlen(b);k++){
            if(a[i]==b[k]){
                if(a[i]==b[++k])
                    printf("%c",a[i]);

            }
        }
    }
    printf("\n");
   return 0;
}