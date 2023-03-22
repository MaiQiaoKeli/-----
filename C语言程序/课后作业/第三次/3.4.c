#include <stdio.h>

void fanzuan();
 
int main()
{
    printf("输入字符串: ");
    fanzuan();
    return 0;
}
 
void fanzuan()
{
    char c;
    scanf("%c", &c);
    if( c != '\n'){
        fanzuan();
        printf("%c",c);
    }
}