#include <stdio.h>

#define QUEUE_SIZE 5
#define NO_DATA -1
int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;
int num = 0;

int EnQueue(int data);
int DeQueue();
void ShowQueue();

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
    if (num >= QUEUE_SIZE)
    { //データ数が配列を超えるとき
        return (-1);
    }
    rear++;
    if (rear >= QUEUE_SIZE)
    {
        rear = 0; // rearがこえたらリングバッファ
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

int main()
{
    int i, mode, data, ret;
    // 初期化
    for (i = 0; i < QUEUE_SIZE; i++)
        queue[i] = NO_DATA;
    // 選択
    while (1)
    {
        printf("(1) Enqueue (2) Dequeue (0) Exit :");
        scanf("%d", &mode);
        if (mode == 0)
        {
            break;
        }
        else if (mode == 1)
        {
            printf("Data: ");
            scanf("%d", &data);
            ret = EnQueue(data);
            if (ret == -1)
                printf("Queue is Full!\n");
            else
                ShowQueue();
        }
        else if (mode == 2)
        {
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
        else
        {
            printf("は？\n");
        }
    }
}