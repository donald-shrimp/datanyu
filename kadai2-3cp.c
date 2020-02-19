#include <stdio.h>
int Factrial(int n);

int main()
{
  int fact, n;
  printf("自然数を入力してください:");
  scanf("%d", &n);
  fact = Factrial(n);
  printf("%dの階乗は,%dです.\n", n, fact);

  return 0;
}

int Factrial(int n)
{  

  if (n == 0)
  {
    printf("関数Factrial(%d)から出ます.:Factrial(%d)=%d\n", n, n, n);
    return 1;
  }else{
    printf("関数Factrial(%d)にはいりました.\n", n);
    return n * Factrial(n - 1);  
  }
}
