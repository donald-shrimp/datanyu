#include <stdio.h>
#define NUM 1000				//  配列サイズ
int n_comp=0, n_exchange=0;		//  比較回数と交換回数(グローバル変数)
void  bubble( int x[NUM], int num );
void  swap( int *a, int *b );
int  main(void)
{
    int  i, num, x[NUM];
    printf("何回？：");
    scanf("%d",&num);	//  データ数numを読み込む
    for( i=0;i<num;i++ ){		//  num個の整数データを入力
      scanf("%d",&x[i]);		
    }
    printf("整列前データ："); 		//  整列前の配列を表示
    for( i=0;i<num;i++ ){
      printf("%4d", x[i] );
    }
    printf("\n");
    bubble(x,num);	//  バブルソート
    printf("整列後データ：");		//  整列後の配列を表示
    for( i=0;i<num;i++ ){
        printf( "%4d", x[i] );
    }
    printf("\n");
    printf("比較回数：%d\n", n_comp);		//  表示
    printf("交換回数：%d\n", n_exchange);	//  表示
}

void bubble(int x[], int num) {
  int i,j;
  for (i=0;i<num-1;i++) {
    for (j=num-1;j>i;j--) {
      n_comp++;
      if (x[j-1]>x[j]) {
	swap (&x[j-1],&x[j]);
	n_exchange++;
      }
    }
  }
}

void  swap( int *a, int *b )
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
