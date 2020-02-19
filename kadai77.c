#include <stdio.h>
#define NUM 5
/* count0:比較回数, count1:交換回数 */
int count0 = 0, count1 = 0; /* グローバル変数として初期化　*/
void swap(int *x, int *y);  /* 関数プロトタイプ　*/
void bubble(int a[], int n);/* 関数プロトタイプ　*/
int main(void)
{
    int i;
    int x[NUM];
    printf("Input integer number %d times ¥n", NUM);
    for (i = 0; i < NUM; i++)
    {
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }
    bubble(x, NUM);
    printf("Sorting is finished \n");
    for (i = 0; i < NUM; i++)
        printf("x[%d] =%d\n", i, x[i]);
    printf("Number of comparison=%d\n", count0);
    printf("Number of swap=%d\n", count1);
    return (0);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                count0++;
                swap(&a[j - 1], &a[j]);
                count1++;
            }
            else
                count0++;
        }
    }
}