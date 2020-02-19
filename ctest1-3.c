#include<stdio.h>
int koyakusu(int a,int b);
int main(){
  int a,b,x;
  printf("二つの自然数を入力しなさい\n");
  printf("aの値は？:");
  scanf("%d",&a);
  printf("bの値は？:");
  scanf("%d",&b);
  x=koyakusu(a,b);
  printf("%dと%dの最大公約数は%dです\n",a,b,x);
  return 0;
}

int koyakusu(int a,int b){
  int r;
  r=a%b;
  if(r==0){
    return b;
  }
  return koyakusu(b,r);
}
