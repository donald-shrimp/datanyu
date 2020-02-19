#include<stdio.h>

void print_board(int board[3][3]); /*プロトタイプ宣言*/
void mark_board(int board[3][3], int turn);

int main(){
  int board[3][3]={}; /*0で初期化*/
  int turn=1;
  mark_board(board,turn);
  print_board(board);
  return 0;
}

void print_board(int board[3][3]){
  int i,j;

  for(i=0;i<3;i++){
    printf("|");
    for(j=0;j<3;j++){
      switch(board[i][j]){
      case 0:
	printf(" ");
	break;
      case 1:
	printf("o");
	break;
      case -1:
	printf("x");
	break;
      }
      printf("|");
    }
    printf("\n");
  }
}

void mark_board(int board[3][3], int turn){
  int i,j;
  if(turn==1){
    printf("oのターンです\n");
  }else if(turn==-1){
    printf("xのターンです\n");
  }
  printf("縦位置は？");
  scanf("%d",&i);
  printf("横位置は？");
  scanf("%d",&j);
  board[i][j]=turn;
  turn=turn*(-1);
}
