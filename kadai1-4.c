#include <stdio.h>
void print_board(int board[3][3]); /*プロトタイプ宣言*/
void mark_board(int board[3][3], int turn);
int judge(int board[3][3]);
int count = 0;
void print_message(int result);
int main()
{
  int board[3][3] = {}; /*0で初期化*/
  int turn = 1, result;
  while (1)
  {
    mark_board(board, turn);
    print_board(board);
    turn = turn * (-1);
    result = judge(board);
    if(result==1||result==-1||result==-2)
      break;
  }
   print_message(result);
  return 0;
}

void print_board(int board[3][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
    printf("|");
    for (j = 0; j < 3; j++)
    {
      switch (board[i][j])
      {
      case 0:
        printf("　");
        break;
      case 1:
        printf("〇");
        break;
      case -1:
        printf("Ｘ");
        break;
      }
      printf("|");
    }
    printf("\n");
  }
}

void mark_board(int board[3][3], int turn)
{
  int i, j;
  if (turn == 1)
  {
    printf("〇のターンです\n");
  }
  else if (turn == -1)
  {
    printf("Ｘのターンです\n");
  }
  do
  {
    printf("縦位置は？");
    scanf("%d", &i);
    printf("横位置は？");
    scanf("%d", &j);
    if (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != 0)
      printf("不正な位置です\n");
  } while (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != 0);
  board[i][j] = turn;
  turn = turn * (-1);
}

int judge(int board[3][3])
{
  int i;
  count++;

  for (i = 0; i < 3; i++)
  {
    /*タテ*/
    if (board[i][1] == board[i][2] && board[i][1] == board[i][0])
    {
      return board[i][1];
    }
    /*ヨコ*/
    if (board[2][i] == board[1][i] && board[1][i] == board[0][i])
    {
      return board[1][i];
    }
    /*ナナメ*/
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
      return board[1][1];
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
      return board[1][1];
    }
    /*ヒキワケ*/
    if (count  > 8)
    {
      return -2;
    }  
  }
  return 0;
}

void print_message(int result){
  if(result==1){
      printf("〇の勝ちです\n");
      
    }else if(result==-1){
      printf("Ｘの勝ちです\n");
      
    }else if(result==-2){
      printf("引き分けです\n");
      
    }
}
