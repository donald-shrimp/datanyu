#include<stdio.h>
#include<math.h>

struct point{
  double x;
  double y;
};

double kyori(struct point zahyo[3]);

int main(void){
  
  int i;
  double dis;
  struct point zahyo[3];
  
  printf("XY座標面上の任意の3点を入力してください\n");
  for(i = 0; i < 3; i++){
    printf("%d点目\n",i+1);
    printf("X座標：");
    scanf("%lf", &zahyo[i].x);
    printf("Y座標：");
    scanf("%lf", &zahyo[i].y);
  }
  
  dis = kyori(zahyo);
  if (dis == -1)
    printf("計算不能\n");
  else
    printf("三角形の周囲は%lfです\n", dis);
  return 0;
}

double kyori(struct point zahyo[3]){
  double a, b, c,syui;
  int kyori1, kyori2, kyori3;
  
  a = sqrt((zahyo[1].x - zahyo[0].x) * (zahyo[1].x - zahyo[0].x) + (zahyo[1].y - zahyo[0].y) * (zahyo[1].y - zahyo[0].y));
  b = sqrt((zahyo[2].x - zahyo[1].x) * (zahyo[2].x - zahyo[1].x) + (zahyo[2].y - zahyo[1].y) * (zahyo[2].y - zahyo[1].y));
  c = sqrt((zahyo[2].x - zahyo[0].x) * (zahyo[2].x - zahyo[0].x) + (zahyo[2].y - zahyo[0].y) * (zahyo[2].y - zahyo[0].y));
  
  kyori1 = (int)(a*100000);
  kyori2 = (int)(b*100000);
  kyori3 = (int)(c*100000);
  
  if(kyori1 + kyori2 <= kyori3  ||  kyori1 + kyori3 <= kyori2  ||  kyori2 + kyori3 <= kyori1)
    syui = -1;
  else
    syui = a + b + c;
  
  return syui;
}
