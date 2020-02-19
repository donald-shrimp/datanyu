#include <stdio.h>
#define NUM 10

void insertion(int x[], int num);
int bin_search(int x[], int num, int key);
int main(void)
{
	int 	i,ky,idx;
	int	x[NUM];

	printf("Input integer number %d times \n",NUM);
	for (i=0;i<NUM;i++)	{
		printf("x[%d]:",i);
		scanf("%d",&x[i]);
	}
	insertion(x,NUM);
	printf("ソート結果\n");
	for ( i = 0; i < NUM; i++)
	{
		printf("x[%d]=%d\n",i,x[i]);
	}
	

	printf("Number to search:");
	scanf("%d",&ky);
	
	idx=bin_search(x,NUM,ky);

	if (idx==-1)	
		printf("Searching was failed!\n");
	else
		printf("%d is located at %d \n",ky,idx);		
	return(0);
}

void insertion(int x[], int num) 
{
  int i,j,tmp;
  for (i=1;i<=num-1;i++) {
    tmp=x[i];
    j=i;
    while ((x[j-1]>tmp) && (j>0)) {
      x[j]=x[j-1];
      j--;
    }
    x[j]=tmp;
  }                                                    
}

int bin_search(int x[], int num, int key){
	int pl=0,pr=num-1,pc;
	while (1){
		pc=(pl+pr)/2;
		if (pl>pr){
			return -1;
		}else if (x[pc]==key){
			return pc;
		}else if (x[pc]<key){
			pl=pc+1;
		}else if (x[pc]>key){
			pr=pc-1;
		}		
	}
}  
