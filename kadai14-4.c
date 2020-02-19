#include<stdio.h>
#define N 10
#define Qua 4
int main(){
    double popu[Qua][3],max;
    int i,tmp;
    FILE *fp;
    char name[Qua][N];
    for (i = 0; i < Qua; i++)
    {
        printf("%d番目の都道府県名は？:",i+1);
        scanf("%s",name[i]);
        printf("人口は？:");
        scanf("%lf",&popu[i][0]);
        printf("面積(Km²)は？:");
        scanf("%lf",&popu[i][1]);
        popu[i][2]=popu[i][0]/popu[i][1];       
    }
    for ( i = 0; i < Qua; i++){
            if (i==0){
                max=popu[i][2];
                tmp=i;
            }else if (max<popu[i][2]){
                max=popu[i][2];
                tmp=i;
            }
        }
    printf("\nファイル test.txt に出力します.\n");
    fp=fopen("test.txt","w");
    for ( i = 0; i < Qua; i++){
        fprintf(fp,"%s　%.0lf　%.0lf　%.1lf\n",name[i],popu[i][0],popu[i][1],popu[i][2]);
    }
    fprintf(fp,"-------------------------------------\nもっとも人口密度が高いのは%sです\n",name[tmp]);
    fclose(fp);
    return 0;
}