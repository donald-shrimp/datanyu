#include <stdio.h>
#include<stdlib.h>
#define NUM 1000                                //  配列サイズ                  
int n_comp=0,n_comp2=0, n_exchange=0, n_shift=0,n_in=0;             //  比較回数と交換回数(グローバル変数)
void  insertion( int x[], int num );     
void  bubble( int x[NUM], int num );
void  swap( int *a, int *b );
int  main(void)
{
  int  i, num, data_bub[NUM],data_ins[NUM];
  printf("何回？：");
  scanf("%d",&num);   //  データ数numを読み込む
  for(i=0;i<num;i++){
    data_bub[i]=rand();
    data_ins[i]=data_bub[i];
  }
  
  printf("\n");
  bubble(data_bub,num);      //  バブルソート
  insertion(data_ins,num);                   //  挿入法 
    
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
  printf("挿入法\n");
  printf("比較回数：%d\n", n_comp);           //  表示                                                 
  printf("シフト回数：%d\n", n_shift);        //  表示                                                 
  printf("挿入回数：%d\n", n_in);        //  表示                                                      
}


void bubble(int x[], int num) {
  int i,j;
  for (i=0;i<num-1;i++) {
    for (j=num-1;j>i;j--) {
      n_comp2++;
      if (x[j-1]>x[j]) {
        swap (&x[j-1],&x[j]);
        n_exchange++;
      }
    }
  }
  printf("バブル\n");
  printf("比較回数：%d\n", n_comp2);           //  表示
  printf("交換回数：%d\n", n_exchange);       //  表示
}

void  swap( int *a, int *b )
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}




