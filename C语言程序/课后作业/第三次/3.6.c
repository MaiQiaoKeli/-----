#include <stdio.h>

long long s (int rows, int n);
long long d(int n);
long long agh(int x,int n);

int main()
{
    int te = 0;
    scanf("%d",&te);
    long long re[te];

    for (int i = 0; i < te; i++)
    {
        int n = 0, m = 0;
        char command[3] = {0};
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%s",command);
        int operate_code = command[0]+command[1];
        if (operate_code == 153 || operate_code == 158)
        {
            re[i] = n*m*(agh(2,n)-1);
        }else{
            re[i] = m*d(n)/2;
        }
    }

    for (int i = 0; i < te; i++)
    {
        printf("%lld\n",re[i]);
    }
    
    return 0;
}

long long s (int rows, int n) 
{
    long long s = 0;
    for (int i = rows; i <= rows + n - 1; i++)
    {
        s += agh(2,i);
    }
    return s;
}

long long d(int n)
{
    long long d = 0;
    for (int i = 1; i <= n; i++)
    {
        d += s(i,n);
    }
    return d;
}
long long agh(int x,int n)
{
    int m=0;
    m=n;
    int t=1;
    while(m>0)
    {
        m/=2;
        t*=2;
    }
    m=n;
    int y=1;
    while(t>1)
    {
        t/=2;
        y*=y;
 
        if (m>=t)
        {
                y*=x;
                m-=t;
        }
    }
    return y;
}
