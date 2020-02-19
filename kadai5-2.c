#include<stdio.h>
struct student{
  int id;
  char name[20];
  int math,eng,ja;
};
int main(){
  struct student gakusei[]={{306001,"阿部",82,72,90},
			    {306051,"佐藤",68,50,62},
			    {306101,"鈴木",42,65,52},
			    {306151,"高橋",92,34,46},
			     {306201,"渡辺",50,70,74}};
  int i;
  double avem,avee,avej;
  printf("\t成績リスト\t\n学生番号\t氏名\t数学\t英語\t国語\t合計\n");
  for(i=0;i<5;i++){
    int sum=0;
    if(i==0){
      avem=0;avee=0;avej=0;
    }
    avem+=gakusei[i].math;
    avee+=gakusei[i].eng;
    avej+=gakusei[i].ja;
    sum=gakusei[i].math+gakusei[i].eng+gakusei[i].ja;
    printf("%d\t\t%s\t%d点\t%d点\t%d点\t%d点\n",gakusei[i].id,gakusei[i].name,gakusei[i].math,gakusei[i].eng,gakusei[i].ja,sum);
  }
  printf("平均点\t\t\t%.1lf点\t%.1lf点\t%.1lf点\n",avem/5,avee/5,avej/5);
  return 0;
}
