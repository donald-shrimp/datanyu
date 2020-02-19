#include <stdio.h>
#include <string.h>
#define NUM 1000//  配列サイズ
struct stu{
  char name[NUM];
  double hei,wei;
};
void insertion(struct stu x[10], int num);

int  main(void){
  int  i, num=10;
  struct stu dent[]={{"阿部",178.5,72.4},
    {"佐藤",168.8,55.5},
    {"鈴木",163.5,82.3},
    {"高橋",185.0,76.5},
    {"田中",175.1,64.2},
    {"友近",172.3,68.2},
    {"中島",179.7,77.1},
    {"原田",182.1,69.3},
    {"安田",174.5,58.8},
    {"渡辺",176.3,65.6}};

  printf("入れ替え前\n");
  for(i=0;i<num;i++){
    printf("%s %.1lf cm %.1lf Kg\n",dent[i].name,dent[i].hei,dent[i].wei);
  }
  insertion(dent,num); //  挿入法
  printf("\n入れ替え後\n");
  for(i=0;i<num;i++){
    printf("%s %.1lf cm %.1lf Kg\n",dent[i].name,dent[i].hei,dent[i].wei);
  }
  return 0;
}
  
void insertion(struct stu x[10], int num){
  int i,j;
  double tmpw,tmph; //wが重さ、hが高さ
  char tmpn[NUM]; //名前

  for (i=1;i<=num-1;i++) {
    tmpw=x[i].wei;
    tmph=x[i].hei;
    strcpy(tmpn,x[i].name);
    j=i;
    while ((x[j-1].hei<tmph) && (j>0)) {
      x[j].wei=x[j-1].wei;
      x[j].hei=x[j-1].hei;
      strcpy(x[j].name,x[j-1].name);
      j--;
    } 
     x[j].wei=tmpw;
    x[j].hei=tmph;
    strcpy(x[j].name,tmpn);
    
  }
}

