#include <stdio.h>

struct student{
  int id;
  char name[20];
  double height;
  double weight;
};

int main(){
  struct student gakusei[5];
  int i;

  printf("構造体サイズ：%d Bite\n",(int)sizeof(gakusei));
  for(i=0;i<5;i++){
    printf("番号:");
    scanf("%d",&gakusei[i].id);
    printf("名前:");
    scanf("%s",gakusei[i].name);
    printf("身長:");
    scanf("%lf",&gakusei[i].height);
    printf("体重:");
    scanf("%lf",&gakusei[i].weight);
  }
  for(i=0;i<5;i++){
    printf("番号：%d\t名前：%s\t身長：%lf\t体重：%lf\t\n",gakusei[i].id,gakusei[i].name,gakusei[i].height,gakusei[i].weight);
  }
  return 0;
}
