#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 80000
void quick( int a[], int left, int right );
void swap( int *x, int *y );
void  bubble( int x[NUM], int num );
int  main(void){
  int  i, num=5000, data_bub[NUM],data_quick[NUM];
  time_t startq,startb,endq,endb;
  srandom(time(NULL));
  for(i=0;i<NUM;i++){
    data_bub[i]=rand();
    data_quick[i]=data_bub[i];
  }
  for(i=0;i<5;i++){
    startq=clock();
    quick(data_quick,0,num);
    endq=clock();
    printf("<クイックソート法>\n　データ数：%d個\n　計算時間：%f秒\n",num,(float)(endq-startq)/CLOCKS_PER_SEC);
    startb=clock();
    bubble(data_bub,num);
    endb=clock();
    printf("<バブルソート法>\n　データ数：%d個\n　計算時間：%f秒\n",num,(float)(endb-startb)/CLOCKS_PER_SEC);
    num=num*2;
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
    }
    while( data_quick[pr] > pivot ){
      pr--;
    }
    if( pr < pl )
      break;
        
    swap( &data_quick[pl], &data_quick[pr] );
    pl++;
    pr--;
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
      if (x[j-1]>x[j]) {
	swap (&x[j-1],&x[j]);
      }
    }
  }
}
