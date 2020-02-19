#include<stdio.h>
#include<string.h>
#define N 100

int main(){
  char word[N][15]={};
  int num[15]={0},i=0,count;
  while(1){
    printf("%d番目の英単語を入力してください(15文字以内):",i+1);
    scanf("%s",word[i]);
    if(word[i][0]=='*')
      break;
    count=strlen(word[i]);
    num[count-1]++;
    i++;
  }
  printf("文字数　出現回数\n");
  for(i=0;i<15;i++){
    printf("%2d　　　%2d\n",i+1,num[i]);
  }
  return 0;
}
