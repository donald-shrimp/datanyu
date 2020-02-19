#include <stdio.h>
#define N 20
typedef struct {
    int num;
    int next;
}list;
void Showlist(list data[]);
int main(){
    list data[N]={{1,3},{9,2},{4,5},{3,4},{5,1},{15,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
    Showlist(data);
    return 0;
}

void Showlist(list data[]){
    int i;
    printf("ãƒªã‚¹ãƒˆï¼š");
    for ( i = 0; i < N; i++){
        printf("%d  ",data[i].num);
        if(data[i].next==-1){
            break;
        }
    }
    printf("\n");
}
