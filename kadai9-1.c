#include<stdio.h>
void quick( int a[], int left, int right );
void swap( int *x, int *y );
int pass=0;
int main(){
  int a[10] = {1,7,4,6,9,8,3,5,2,10},left=0,right=9,i;
    quick(a,left,right);
    printf("ソート終了：");
      for ( i = 0; i < 10; i++)
      {
        printf("%d ",a[i]);
      }        
      printf("\n");
    return 0;
}

// クイックソート関数
void quick( int a[], int left, int right )
{
    int pl=left;	// left:　左端の添え字
    int pr=right;	// right:　右端の添え字
    int pivot;		// pivot:　pivotの値
    int i;
    pivot = a[(pl+pr)/2];	// ピボットは配列の中央に格納された値
    printf("%d回目の呼び出し：\n",pass+1);
    printf("\t<開始時>\n");
    printf("\t左端の添字：%d\n",left);
    printf("\t右端の添字：%d\n",right);
    printf("\tピボットの添字：%d\n",pivot);
    printf("\tピボットの値：%d\n",a[pivot]);
    printf("\t左端〜右端の値：");
for ( i = left; i <= right; i++){
        printf("%d ",a[i]);
    }

    printf("\n");
printf("\t<ソーティング結果>\n");
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
    printf("\t");
    for ( i = left; i <= right ; i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n");
    
    if( left < pr ){
      pass++;
        quick( a, left, pr );
    }
    if( pl < right ){
      pass++;
        quick( a, pl, right );
    }
    
    
    
}    

void swap( int *x, int *y )
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
