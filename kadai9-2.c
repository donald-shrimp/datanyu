#include<stdio.h>
#include<stdlib.h>
#define NUM 100
int n_comp=0,n_comp2=0, n_exc=0,n_exc2=0;  //  比較回数と交換回数(グローバル変数)
void quick( int a[], int left, int right );
void swap( int *x, int *y );
void  bubble( int x[NUM], int num );
int  main(void){
  int  i, num=20, data_bub[NUM],data_quick[NUM];
  srandom(time(NULL));
  for(i=0;i<NUM;i++){
    data_bub[i]=rand();
    data_quick[i]=data_bub[i];
  }
  for(i=0;i<5;i++){
    n_exc=0;
    n_comp=0;
    quick(data_quick,0,num);                   //  クイックソート
    printf("<クイックソート法>\n　データ数：%d個\n　比較回数：%d回\n　交換回数：%d回\n",num,n_comp,n_exc);
    n_comp2=0;
    n_exc2=0;
    bubble(data_bub,num);      //  バブルソート
    printf("<バブルソート法>\n　データ数：%d個\n　比較回数：%d回\n　交換回数：%d回\n",num,n_comp2,n_exc2);
    num=num+20;
  }
}

// クイックソート関数
void quick( int data_quick[], int left, int right )
{
  int pl=left;// left:　左端の添え字
  int pr=right;// right:　右端の添え字
  int pivot;// pivot:　pivotの値
  
  pivot = data_quick[(pl+pr)/2];// ピボットは配列の中央に格納された値
  while(1){
    while( data_quick[pl] < pivot ){
      pl++;
      n_comp++;
    }
    while( data_quick[pr] > pivot ){
      pr--;
      n_comp++;
    }
    if( pr < pl )
      break;
        
    swap( &data_quick[pl], &data_quick[pr] );
    pl++;
    pr--;
    n_exc++;
  }
  if( left < pr ){
    quick( data_quick, left, pr );
  }
  if( pl < right ){
    quick( data_quick, pl, right );
  }
}

void swap( int *x, int *y )
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void bubble(int x[], int num) {
  int i,j;
  
  for (i=0;i<num-1;i++) {
    for (j=num-1;j>i;j--) {
      n_comp2++;
      if (x[j-1]>x[j]) {
	swap (&x[j-1],&x[j]);
	n_exc2++;
      }
    }
  }
}
