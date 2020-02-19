#include <stdio.h>
#define N 15
int InsertNode(int no, int insdata, int data[]);
int DeleteNode(int no, int data[]);
void Showlist(int data[]);
int main()
{
  int data[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, -1, -1, -1, -1, -1, -1};
  int no = 0, insdata = 0, ynq;
  while (1)
  {
    int res = -1;
    Showlist(data);
    printf("編集選択（挿入=0,　削除=1,　編集終了=2）：");
    scanf("%d", &ynq);
    if (ynq == 0)
    {
      printf("挿入位置：");
      scanf("%d", &no);
      printf("挿入データ：");
      scanf("%d", &insdata);
      res = InsertNode(no - 1, insdata, data);
      if (res == 0)
      {
        printf("成功\n");
      }
      else
      {
        printf("失敗\n");
      }
    }
    else if (ynq == 1)
    {
      printf("削除位置：");
      scanf("%d", &no);
      res = DeleteNode(no - 1, data);
      if (res == 0)
      {
        printf("成功\n");
      }
      else
      {
        printf("失敗\n");
      }
    }
    else if (ynq == 2)
    {
      break;
    }
    else
    {
      printf("は？\n");
    }
  }
  return 0;
}

void Showlist(int data[])
{
  int i;
  printf("リスト：");
  for (i = 0; i < N; i++)
  {
    if (data[i] == -1)
    {
      break;
    }
    printf("%d  ", data[i]);
  }
  printf("\n");
}

int InsertNode(int no, int insdata, int data[])
{
  int n, i;
  //文字数カウント
  for (n = 0; n < N; n++)
  {
    if (data[n] == -1)
    {
      break;
    }
  }
  //配列のデータがいっぱいのとき
  if (n == N)
  {
    return -1;
  }
  //文字を右にずらす
  for (i = n-1; i >= no; i--)
  {
    data[i+1] = data[i];
  }
  //空いたところに挿入
  data[no] = insdata;
  return 0;
}

int DeleteNode(int no, int data[])
{
  int n, i;
  //文字数カウント
  for (n = 0; n < N; n++)
  {
    if (data[n] == -1)
    {
      break;
    }
  }
  //削除位置にデータの有無を確認
  if (no < 0 || n <= no)
  {
    return -1;
  }
  //文字を左にずらす
  for (i = no + 1; i < n; i++)
  {
    data[i - 1] = data[i];
  }
  data[n - 1] = -1;

  return 0;
}
