#include<stdio.h>
#define N 20

int bin(int a[],int key);
int main(void){
  
  int x[N]={1,2,4,5,6,7,9,10,11,13,15,16,17,18,19,20,22,24,27,29};
  int a,i;
  int key[3]={29,10,0};

  for(i=0;i<3;i++){
    printf("探索する値->%d\n",key[i]);
    printf("中央のインデックス->");
    a=bin(x,key[i]);
    if(a==-1){
      printf("\n探索失敗\n");
    }else {
      printf("\nインデックス%d\n\n",a);
    }
  }
  return 0;
}

int bin(int a[],int key){
  int pl,pr,pc;
  pl=0;
  pr=N -1;

  while(1){
    if(pr<pl){
      return -1;
    }
    pc=(pl+pr)/2;
    printf("%3d",pc);
    if(a[pc]<key){
      pl=pc+1;
    }else if(key<a[pc]){
      pr=pc-1;
    }else if(a[pc]==key){
      return pc;
    }
  }
} 
