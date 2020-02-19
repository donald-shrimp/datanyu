#include <stdio.h>
#include <stdlib.h>
#define N 25
//これは降順ソート
struct initial
{
    char character;
    int count;
};

struct initial data[N]={{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0}};
void quick( struct initial data_quick[], int left, int right );
void swap(struct initial *x, struct initial *y );

int main(){
    int i;
    

    while(1){
        char word[N];
        printf("英単語を入力してください：");
        scanf("%s",word);
        if (word[0]=='z') {
                break;
            }
        for (i=0; i<N; i++) {
            
            if(data[i].character==word[0]){
                data[i].count++;
            }
        }
    }
    
    quick(data, 0, N-1 );
    printf("\n出現回数順に出力します\n");
    for (i=0;i<N;i++) {
        if (data[i].count!=0) {
            printf("%c:%d回\n",data[i].character,data[i].count);
        }
        
    }
    
    
}

void quick( struct initial data_quick[], int left, int right )
{
    int pl=left;// left:　左端の添え字
    int pr=right;// right:　右端の添え字
    int pivot;// pivot:　pivotの値
    pivot = data_quick[(pl+pr)/2].count;// ピボットは配列の中央に格納された値
    while(1){
        while( data_quick[pl].count > pivot ){
            pl++;
        }
        while( data_quick[pr].count < pivot ){
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

void swap(struct initial *x, struct initial *y )
{
   struct initial tmp = *x;
    *x = *y;
    *y = tmp;
}