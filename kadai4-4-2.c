#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int main(){
  char word[15]={},*pword[N];
  int num[15]={0},i=0,count=0,*pnum;
  pnum=num;
  while(1){
    printf("%d番目の英単語を入力してください(15文字以内):",i+1);
    scanf("%s",word);
    pword[i]=(char *)malloc(sizeof(char)*(strlen(word)+1));
    strcpy(pword[i],word);
    if(word[0]=='*')
      break;
    count=strlen(*(pword+i)+1);
    *(pnum+count)+=1;
    i++;
  }

  printf("結果の表示法\n\n");
  printf("文字数　出現回数\n");
  for(i=0;i<15;i++){
    printf("%2d　　　%2d\n",i+1,*(pnum+i));
  }
  return 0;
}

