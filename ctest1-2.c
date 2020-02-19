#include<stdio.h>
#include<math.h>
int main(){
  char name[4][10];
  int id[4],i;
  double wei[4],hei[4],hyo,sa[4],heim;
  FILE *fp;
  for(i=0;i<4;i++){
    printf("%d人目の学生番号は（６桁）？：",i+1);
    scanf("%d",&id[i]);
    printf("氏名は？：");
    scanf("%s",name[i]);
    printf("身長(cm)は？：");
    scanf("%lf",&hei[i]);
    printf("体重(Kg)は？：");
    scanf("%lf",&wei[i]);
    heim=hei[i]/100;
    hyo=pow(heim,2)*22;
    sa[i]=wei[i]-hyo;
  }
  fp=fopen("test.dat","w");
  for(i=0;i<4;i++){
    fprintf(fp,"%d %s %.1lf %.1lf %.1lf\n",id[i],name[i],hei[i],wei[i],sa[i]);
  }
  printf("\nファイルtest.datに出力します。\n");
  fclose(fp);
  return 0;
}
