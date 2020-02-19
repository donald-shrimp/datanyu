#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int year,mon,day;
  double wei,hei;
  char family[N],first[N];
  FILE *fp;
  fp=fopen("kadai2.txt","w");
  printf("誕生年:"); scanf("%d",&year);
  printf("誕生月:"); scanf("%d",&mon);
  printf("誕生日:"); scanf("%d",&day);
  printf("\n身長:"); scanf("%lf",&hei);
  printf("体重:");   scanf("%lf",&wei);
  printf("\n名字:"); scanf("%s",family);
  printf("名前:");   scanf("%s",first);

  fprintf(fp,"%d %d %d\n",year,mon,day);
  fprintf(fp,"%lf %lf\n",hei,wei);
  fprintf(fp,"%s %s\n",family,first);
  fclose(fp);
  return 0;
}
