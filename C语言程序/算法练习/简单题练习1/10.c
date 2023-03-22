#include <stdio.h>

// n为待分解自然数
void yinshu(int n)
{
    for (int i = 2; i * i <= n; ++i) { // i的范围可以优化至i*i <= n (sqrt(n)等价于i*i)
        
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if(n!=1)
            printf("*");
        }
    }
    if (n > 1) { // 最后剩下来的就是最大质因数
        printf("%d", n);
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        long n;
        scanf("%d", &n);
        printf("%d=",n);
        yinshu(n);
        putchar('\n');
    }

    return 0;
}


