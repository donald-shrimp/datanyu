#include <stdio.h>
#include <stdlib.h>
#define N 10

struct stu
{
    char name[N];
    int id,ja,ma,en;
};

int bin_search(struct stu x[], int num, int key);

int main(){
    int key,num,sum;
    struct stu dent[N]={{"Erika",6101,98,76,85},
        {"Fumiyasu",6102,47,88,91},
        {"Rika",6103,56,90,78},
        {"Syoya",6104,65,76,83},
        {"Sho",6105,79,73,82},
        {"Tatsuya",6106,89,48,90},
        {"Kazunori",6107,68,77,85},
        {"Katsuhiro",6108,91,65,59},
        {"Tomohiro",6109,79,62,89},
        {"Masato",6110,85,88,79}};
    
    printf("学生番号を入力してください：");
    scanf("%d",&key);

    num=bin_search(dent,N,key);
    if(num==-1){
        printf("その番号の学生はいません");
    }else{
      sum=dent[num].ja+dent[num].ma+dent[num].en;
      printf("%sさん(%d)の成績は、国語%d点,　数学%d点,　英語%d点,　合計%d点です.\n",dent[num].name,dent[num].id,dent[num].ja,dent[num].ma,dent[num].en,sum);
    }
    
}

int bin_search(struct stu x[], int num, int key){
  int pl=0,pr=num-1,pc;
  while (1){
    pc=(pl+pr)/2;
    if (pl>pr){
      return -1;
    }else if (x[pc].id==key){
      return pc;
    }else if (x[pc].id<key){
      pl=pc+1;
    }else if (x[pc].id>key){
      pr=pc-1;
    }		
  }
  return 0;
}
