#include <stdio.h>
void swap(int *x,int *y);
int main(){
  int a,b;
  a=12; b=34;
  swap(&a,&b);
  printf("a:%d.B:%d\n",a,b);
}

void swap(int *x,int *y){
  int wk=0;
  wk=*x;
  *x=*y;
  *y=wk;
  printf("%d,%d,%d\n",wk,*x,*y);
}
 
