#include<stdio.h>
#define N 5
typedef struct{
  int id;
  char name[10];
  int score;
}score;

void quick_sort(score data[],int left,int right);
void swap(score *a,score *b);

int main(void){
  score data[]={{101,"斉藤",76},{103,"田中",53},{100,"中野",81},{102,"松本",93},{104,"吉田",85}};
  int i=0;

  printf("[ソート前]\n学生番号\t名前\t\t点数\n");
  for(i=0;i<N;i++){
    printf("%d\t\t%s\t\t%d\n",data[i].id,data[i].name,data[i].score);
  }
  quick_sort(data,0,N-1);
  printf("\n[ソート後]\n");
  printf("学生番号\t名前\t\t点数\n");
  for(i=0;i<N;i++){
    printf("%d\t\t%s\t\t%d\n",data[i].id,data[i].name,data[i].score);
  }
  return 0;
}

void quick_sort(score data[],int left,int right){

  int pl=left;
  int pr=right;
  int pivot;

  pivot=(data[pl].score+data[pr].score)/2;
  do{
    while(data[pl].score>pivot){
      pl++;
    }
    while(data[pr].score<pivot){
      pr--;
    }
    if(pl<=pr){
      swap(&data[pl],&data[pr]);
      pl++;
      pr--;
    }
  }while(pl<=pr);
  if(left<pr){
      quick_sort(data,left,pr);
    }
    if(pl<right){
      quick_sort(data,pl,right);
    }
  }

  void swap(score *a,score *b){
    score tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;
  }



