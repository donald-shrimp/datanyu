#include <stdio.h>
#define NUM 1000				//  配列サイズ
int n_comp=0, n_shift=0,n_in;		//  比較回数と交換回数(グローバル変数)
void  insertion( int x[], int num );
int  main(void)
{
    int  i, num, x[NUM];
    printf("何回？：");
    scanf("%d",&num);                   //  データ数numを読み込む
    for( i=0;i<num;i++ ){		//  num個の整数データを入力
    scanf("%d",&x[i]);		
    }
    printf("整列前データ："); 		//  整列前の配列を表示
    for( i=0;i<num;i++ ){
        printf("%4d", x[i] );
    }
    printf("\n");
    insertion(x,num);	                //  挿入法
    printf("整列後データ：");		//  整列後の配列を表示
    for( i=0;i<num;i++ ){
        printf( "%4d", x[i] );
    }
    printf("\n");
    
}
  
void insertion(int x[], int num)
{
  int i,j,tmp;
  for (i=1;i<=num-1;i++) {
    tmp=x[i];
    j=i;
    while ((x[j-1]>tmp) && (j>0)) {
      x[j]=x[j-1];
      j--;
      n_comp+=2; /* 比較 */ 
      n_shift++; /* シフト */
    } 
    x[j]=tmp;
    n_in++; /* 挿入 */
    n_comp+=2; /* 比較 */
  }
    printf("比較回数：%d\n", n_comp);		//  表示
    printf("シフト回数：%d\n", n_shift);	//  表示
    printf("挿入回数：%d\n", n_in);        //  表示 
}


