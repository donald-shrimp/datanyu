#include<stdio.h>
#define N 100
struct stu{
  char name[N];
  int id,ma,en,ph;
};

int main(){
  struct stu dent[5]={{"Abe",306001,80,73,44},
		      {"Igarashi",306021,62,92,50},
		      {"Sato",306041,82,77,61},
		      {"Suzuki",306051,74,85,94},
		      {"Takahashi",306061,76,54,87}
  };
  int sum[5],max,min,i;
  double avema=0,aveen=0,aveph=0,avesum=0;
  for(i=0;i<5;i++){
    sum[i]=dent[i].ma+dent[i].en+dent[i].ph;
    avema+=dent[i].ma;
    aveen+=dent[i].en;
    aveph+=dent[i].ph;
    avesum+=sum[i];
    if(i==0){
      max=sum[i];
      min=sum[i];
    }
    if(max<sum[i]){
      max=sum[i];
    }else if(min>sum[i]){
      min=sum[i];
    }
  }
  for(i=0;i<5;i++){
    printf("%s (%d)の合計点は：%d点\n",dent[i].name,dent[i].id,sum[i]);
  }
  
  printf("合計点の最高は：%d点\n合計点の最低は：%d点\n合計点の平均は：%.1lf点\n英語の平均点は：%.1lf点\n数学の平均点は：%.1lf点\n物理の平均点は：%.1lf点\n",max,min,avesum/5,aveen/5,avema/5,aveph/5);
  return 0;
  
  }
