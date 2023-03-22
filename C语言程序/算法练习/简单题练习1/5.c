#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char matrix[n][n];

        for(int i=0;i<n;i++){
            getchar();
            for(int j=0;j<n;j++){
                matrix[i][j]=getchar();
            }
          
        }

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                printf("%c",matrix[j][i]);
            }
            printf("\n");
        }
        putchar('\n');
    }
}