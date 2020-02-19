#include <stdio.h>
int point(int n);
int main()
{
    int n;
    printf("いくつ買いますか？:");
    scanf("%d", &n);
    printf("ポイントは%d点です\n", point(n));
    return 0;
}

int point(int n)
{
    int x=0;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        x = 10 + point(n - 1);
    }
    else if (n < 11 && n > 1)
    {
        x = 5 + point(n - 1);
    }
    else if (n >= 11)
    {
        x = 1.1 * point(n - 1);
    }
       return x;
}
