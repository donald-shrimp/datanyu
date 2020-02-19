#include<stdio.h>
#define STACK_SIZE 10 //スタックの最大データ数

int stack[STACK_SIZE];
int sp=-1;
char getchr();
int push(int data);
int pop();
int main(){
    printf("逆ポーランド記法で記述された数式を入力してください\n");
    while(1){
        char type[1];
        type[0] = getchar();
        int op2;
		switch (type[0]) {
		case '1':
			push(1);
			break;
		case '2':
			push(2);
			break;
        case '3':
			push(3);
			break;
        case '4':
			push(4);
			break;
        case '5':
			push(5);
			break;
        case '6':
			push(6);
			break;
        case '7':
			push(7);
			break;
        case '8':
			push(8);
			break;
        case '9':
			push(9);
			break;
        case '0':
			push(0);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '\n':
			printf("計算結果＝ %d \n", pop());
			break;
		default:
			printf("error: unknown command %s\n",type);
			break;
		}
        if(type[0]=='\n'){
            break;
        }
	}
    return 0;
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
    int data=-1;   /* データ初期化 */
    if (sp<0){ /* スタックポインタ確認 */
        printf("Stack Empty!\n");
        return (-1); /* 異常終了 */
    }else{
        data=stack[sp]; /* スタック値を代入 */
        sp--; /* スタックポインタ -1 */
        return (data); /* 正常終了 */
    }
}

char getchr(){
    char num[1];
    scanf("%s",&num[0]);
    return num[0];
}