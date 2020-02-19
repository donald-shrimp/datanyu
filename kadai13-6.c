#include <stdio.h>
#define STACK_SIZE 5 //スタックの最大データ数
#define NO_DATA -1   //データがないとき
#define QUEUE_SIZE 5
int queue[QUEUE_SIZE];
int stack[STACK_SIZE];
int sp = -1;
int front = -1;
int rear = -1;
int num = 0;

int EnQueue(int data);
int DeQueue();
void ShowQueue();
int push(int data);
int pop();
void showstack();

int main()
{
    int query, data, pushnum, popnum, ret,i;
    // 初期化
    for (i = 0; i < QUEUE_SIZE; i++)
        queue[i] = NO_DATA;
    //質問ループ
    do
    {
        printf("(1) Push (2) Pop (3) Enq (4) Deq (5) Push(Deq) (6) Enq(Pop) (0) Exit :");
        scanf("%d", &query);
        if (query == 1)
        {//Push
            printf("Data:");
            scanf("%d", &data);
            pushnum = push(data);
            if (pushnum == -1)
            {
                printf("Stack Push is failed!\n");
            }
            else
            {
                showstack();
            }
        }
        else if (query == 2)
        {//pop
            popnum = pop();
            if (popnum == -1)
            {
                printf("Stack Pop is failed!\n");
            }
            else
            {
                printf("Pop data is %d\n", popnum);
                showstack();
            }
        }
        else if (query == 3)
        { //Enq
            printf("Data: ");
            scanf("%d", &data);
            ret = EnQueue(data);
            if (ret == -1)
                printf("Queue is Full!\n");
            else
                ShowQueue();
        }
        else if (query == 4)
        { //Deq
            ret = DeQueue();
            if (ret == -1)
            {
                printf("Queue is Empty!!\n");
            }
            else
            {
                printf("Dequeue data is %d\n", ret);
                ShowQueue();
            }
        }
        else if (query == 5)
        { //Push(Deq)
            ret = DeQueue();
            if (ret == -1)//Deqが失敗
            {
                printf("Queue is Empty!!\n");
            }
            else //Deqは成功、pushの可否を判断
            {
                printf("Dequeue data is %d\n", ret);
                ShowQueue();
                pushnum = push(ret);
                if (pushnum == -1)
                {
                    printf("Stack Push is failed!\n");
                }
                else
                {
                    showstack();
                }
            }
        }
        else if (query == 6)
        { //Enq(Pop)
            popnum = pop();
            if (popnum == -1)//stack失敗
            {
                printf("Stack Empty!\nStack Pop is failed!\n");
            }
            else//stack成功、popの可否
            {
                printf("Pop data is %d\n", popnum);
                showstack();
                ret = EnQueue(popnum);
                if (ret == -1)
                    printf("Queue is Full!\n");
                else
                    ShowQueue();
            }
        }
        else if(query<0||query>6)
        { //その他の番号
            printf("は？\n");
        }
    } while (query != 0);
}

int push(int data)
{
    sp++; /* スタックポインタ +1 */
    if (sp >= STACK_SIZE)
    { /* 配列サイズ超過 */
        printf("Stack Overflow!\n");
        sp--;
        return (-1); /* 異常終了 */
    }
    else
    {
        stack[sp] = data; /* データ代入 */
        return 0;         /* 正常終了 */
    }
}

int pop()
{
    int data = 0; /* データ初期化 */
    if (sp < 0)
    { /* スタックポインタ確認 */
        printf("Stack Empty!\n");
        return (-1); /* 異常終了 */
    }
    else
    {
        data = stack[sp]; /* スタック値を代入 */
        sp--;             /* スタックポインタ -1 */
        return (data);    /* 正常終了 */
    }
}

void showstack()
{
    int i;
    printf("Stack :");
    for (i = 0; i <= sp; i++)
    {
        printf(" [%d]", stack[i]);
    }
    printf("\n");
}

void ShowQueue()
{
    int i;
    printf("Queue : ");
    for (i = 0; i < QUEUE_SIZE; i++)
    {
        if (queue[i] != NO_DATA)
        {
            printf("[%d]", queue[i]);
        }
        else
        {
            printf("[ ]");
        }
    }
    printf("\n");
}

int EnQueue(int data)
{
    int temp;
    temp = rear;
    rear++;
    if (rear >= QUEUE_SIZE)
    {
        rear = 0; // rearがこえたらリングバッファ
    }
    if (num >= QUEUE_SIZE)
    { //データ数が配列を超えるとき
        rear = temp;
        return (-1);
    }
    else
    {
        queue[rear] = data; //最後尾にデータ挿入
        num++;
        return 0;
    }
    return 0;
}

int DeQueue()
{
    if (num == 0)
    {
        return (-1); // データなし
    }
    else
    {
        int data;
        front++;
        if (front == QUEUE_SIZE)
            front = 0;          // frontが配列サイズを超えたらリングバッファを設定
        data = queue[front];    // デキュー：frontデータをdataに保存
        queue[front] = NO_DATA; // frontデータに無効データを入れる
        num--;
        return (data); // デキューしたデータを返却
    }
}