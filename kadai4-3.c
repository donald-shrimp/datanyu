#include <stdio.h>
#include <stalib.h>

int main(){
  int i;
  char name[]="Nihon University";
  char *p,*str;
  int num=0;//スペース記号の位置を格納

  //スペース記号の位置を調べる
  p=name;
  if(*p==' '){
    printf("%d文字目に見つかりました！\n",num);
    break;
  }
  p++;
}

str=(char*)malloc(num* sizeof(char));

for(i=0;i<num;i++){
  *(str+i)=name[i];
 }
*(str+i)='\0';

printf("%s\n",str);
  
free(str);
  
return 0;

}
