#include<stdio.h>
#define STACK_SIZE 5 //スタックの最大データ数
#define NO_DATA -1 //データがないとき

int stack[STACK_SIZE];
int sp=-1;

int push(int data);
int pop();
void showstack();

int main(){
    int query,data,pushnum,popnum;
    //質問ループ
    do{
        printf("(1) Push (2) Pop (0) Exit :");
        scanf("%d",&query);
        //Push
        if(query==1){
            printf("Data:");
            scanf("%d",&data);
            pushnum=push(data);
            if(pushnum==-1){
                printf("Stack Push is failed!\n");
            }else{
                showstack();
            }
         //pop
        }else if(query==2){
            popnum=pop();
            if (popnum==-1) {
                printf("Stack Pop is failed!\n");
            }else{
                printf("Pop data is %d\n",popnum);
                showstack();
            }
        //その他の番号
        }else if(query<0||query>2){
            printf("は？\n");
        }
    }while (query!=0);
}

int push(int data){
    sp++; /* スタックポインタ +1 */
    if (sp>=STACK_SIZE){ /* 配列サイズ超過 */
        printf("Stack Overflow!\n");
        sp--;
        return (-1); /* 異常終了 */
    }else{
        stack[sp]=data; /* データ代入 */
        return 0; /* 正常終了 */
    }
}

int pop(){
    int data=0;   /* データ初期化 */
    if (sp<0){ /* スタックポインタ確認 */
        printf("Stack Empty!\n");
        return (-1); /* 異常終了 */
    }else{
        data=stack[sp]; /* スタック値を代入 */
        sp--; /* スタックポインタ -1 */
        return (data); /* 正常終了 */
    }
}

void showstack(){
    int i;
    printf("Stack :");
    for (i=0;i<=sp;i++) {
        printf(" [%d]",stack[i]);
    }
    printf("\n");
}