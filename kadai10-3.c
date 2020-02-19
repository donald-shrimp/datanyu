#include <stdio.h>
#include <stdlib.h>

#define MAX 2000
#define FMAX 20

void swap(int *x, int *y);
void quick(int a[],int left, int right);
int bin_search(int x[], int n, int key);
int lin_search(int x[], int n, int key);

int main(void)
{
  int 	i;
  int	seisu[MAX];
  int	kosu,ky,idx0,idx1;
  char 	fname[FMAX];
  FILE 	*fp;
  
  kosu=MAX;			/* データ個数をkosuに代入　*/
  printf("Input file name:");
  scanf("%s",fname);		/* ファイル名の読み込み　*/
  
  fp=fopen(fname,"r");		/* ファイルオープン　*/
  
  if (fp==NULL)	{		/* ファイルオープン時のエラー処理　*/
    printf("No file found !");
    exit(1);
  }	
  
  //（１）	ファイルからデータをkosu個読み込み配列seisuに入れる。
  for (i=0;i<kosu ; i++) {
    fscanf(fp,"%d",&seisu[i]);
  }
  printf("Number to search:");
  scanf("%d",&ky);			/* キーを変数kyに入力する　*/
  //（２）線形探索を行い結果を変数idx0に出力する。
  idx0=lin_search(seisu,kosu,ky);
  //（３）クイックソート及び二分探索を行い結果を変数idx1に出力する。
    quick(seisu,0,kosu);
    idx1=bin_search(seisu,kosu,ky);
  //（４）(２)の線形探索、(３)の二分探索にかかった計算回数を表示する。
  printf("<計算回数>\n線形探索：%d\n二分探索：%d\n",idx0+1,idx1);
  fclose(fp);			/* ファイルクローズ　*/
  return(0);
}

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void quick(int a[],int left, int right)
{
  int pl=left;// left:　左端の添え字
    int pr=right;// right:　右端の添え字
    int pivot;// pivot:　pivotの値
    pivot = a[(pl+pr)/2];// ピボットは配列の中央に格納された値
    while(1){
      while( a[pl] < pivot ){
	pl++;
      }
      while( a[pr] > pivot ){
	pr--;
      }
      if( pr < pl )
	break;
        
      swap( &a[pl], &a[pr] );
      pl++;
      pr--;
    }
    if( left < pr ){
      quick( a, left, pr );
    }
    if( pl < right ){
        quick( a, pl, right );
    }
}

int bin_search(int x[], int num, int key){
  int pl=0,pr=num-1,pc,times=0;
  while (1){
    pc=(pl+pr)/2;
      times++;
    if (pl>pr){
      return -1;
    }else if (x[pc]==key){
      return times;
    }else if (x[pc]<key){
      pl=pc+1;
    }else if (x[pc]>key){
      pr=pc-1;
    }		
  }
  return 0;
}

int lin_search(int a[], int n, int key)
{
  int	i=0;
  
  while(1) {
    if (i==n)
      return (-1);
    if (a[i]==key)
      return (i);
    i++;
  }
}	
