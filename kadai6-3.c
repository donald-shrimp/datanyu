#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(void){
  FILE *fp;
  int year,mon,day,old;
  double wei,hei;
  char family[N],first[N];
  fp=fopen("kadai2.txt","r");
  fscanf(fp,"%d %d %d",&year,&mon,&day);
  fscanf(fp,"%lf %lf",&hei,&wei);
  fscanf(fp,"%s %s",family,first);
  fclose(fp);
  if(mon<=4){
    old=2019-year;
  }else if(mon==5&&day<=26){
    old=2019-year;
  }else{
    old=2018-year;
  }

  printf("氏名は%s %sです\n",family,first);
  printf("生年月日は%d年%d月%d日です（%d歳）\n",year,mon,day,old);
  printf("身長は %lf cm 体重は %lf Kg です\n",hei,wei);
  
  return 0;
}
