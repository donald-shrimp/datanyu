#include <stdio.h>
#define N 10
void Showlist(int data[]);
int main(){
    int data[]={2,4,6,8,10,12,14,16,18,-1};
    Showlist(data);
    return 0;
}

void Showlist(int data[]){
    int i;
    printf("リスト：");
    for ( i = 0; i < N; i++){
        if(data[i]==-1)
            break;
        printf("%d  ",data[i]);
        
    }
    printf("\n");
}