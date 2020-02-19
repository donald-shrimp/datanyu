#include <stdio.h>
#include <stdlib.h>

//学生情報を示す構造体
struct student{
  //学生番号
  int id;
  //氏名
  char name[32];
};

int main(){
  int i;
  FILE *fp;
  //学生情報
  struct student gakusei[5]={{306001,"sato"},{306002,"suzuki"},{306003,"tanaka"}};
  //ファイルを書き込みモードで開く
  fp=fopen("kadai1.txt","w");
  //学生情報をファイルに出力
  for(i=0;i<3;i++){
    fprintf(fp,"%d %s\n",gakusei[i].id,gakusei[i].name);
  }
  //ファイルを閉じる
  fclose(fp);

  return 0;
}
