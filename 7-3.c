#include<stdio.h>
#include<stdlib.h>
#define NUM 1000

int n_comp=0,n_comp2=0,n_exchange=0,n_shift=0,n_insert=0;

void insertion(int x[],int num);
void bubble(int x[],int num);
void swap(int *a,int *b);

int main(){
  int i,num;
  int data_bub[NUM];
  int data_ins[NUM];
  
  printf("データの数:");
  scanf("%d",&num);
  for(i=0;i<num;i++){
    data_bub[i]=rand();
    data_ins[i]=data_bub[i];
  }
  
  bubble(data_bub,num);
  insertion(data_ins,num);

  printf("バブルソート\n");
  printf("n_comp=%d,n_exchange=%d \n",n_comp,n_exchange);
  printf("\n挿入法\n");
  printf("n_comp2=%d,n_shift=%d,n_insert=%d \n",n_comp2,n_shift,n_insert);

  return 0;
}

void insertion(int data_ins[],int num){
  int i,j,tmp;
  for(i=1;i<=num-1;i++){
    tmp=data_ins[i];
    j=i;
    while(data_ins[j-1]>tmp && j>0){
      data_ins[j]=data_ins[j-1];
      j--;
      n_comp2+=2;
      n_shift++;
    }
    data_ins[j]=tmp;
    n_comp2+=2;
    n_insert++;
  }
}

void bubble(int data_bub[],int num){
  int i,j;
  for(i=0;i<num-1;i++){
    for(j=num-1;j>i;j--){
      if(data_bub[j-1]>data_bub[j]){
        n_comp++;
        swap(&data_bub[j-1],&data_bub[j]);
        n_exchange++;
      }
      else
        n_comp++;
    }
  }
}

void swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
