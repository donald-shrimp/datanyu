#include <stdio.h>
#include <math.h>
struct tri{
  double x,y;
};
double distance(struct tri angle[3]);
int main(){
  struct tri angle[3];
  int i;
  double dis;
  
  for(i=0;i<3;i++){
    printf("点%d\n",i+1);
    printf("X座標:");scanf("%lf",&angle[i].x);
    printf("Y座標:");scanf("%lf",&angle[i].y);
  }
  dis=distance(angle);
  if (dis==0){
    printf("計算不能\n");
  }else{
    printf("三角形の周囲の距離:%lf\n",dis);
  }
  
}

double distance(struct tri angle[3]){
  double dis[3],distance,a1,a2,b1,b2,c1,c2;
a1=angle[1].x-angle[0].x;
a2=angle[1].y-angle[0].y; 
b1=angle[2].x-angle[0].x; 
b2=angle[2].y-angle[0].y;
c1=angle[1].x-angle[2].x;
c2=angle[1].y-angle[2].y;

  dis[0]=sqrt((a1*a1)+(a2*a2));
  dis[1]=sqrt((b1*b1)+(b2*b2));
  dis[2]=sqrt((c1*c1)+(c2*c2));
  distance=dis[0]+dis[1]+dis[2];
  if(dis[0]+dis[1]<dis[2]){
    return 0;
  }
  return distance;
}
