#include <stdio.h>
#include <stdlib.h>

# define MaxSize 5

typedef struct{
    int data[MaxSize]; //数据
    int front;         //头指针
    int rear ;         //尾指针
}CircularQueue;


void InitQueue(CircularQueue *Q){
    Q->front = 0;
    Q->rear  = 0;
}

int IsEmpty(CircularQueue *Q){
    return Q->front == Q->rear;
}

int IsFull(CircularQueue *Q){
    return (Q->rear + 1)%MaxSize == Q->front;
}


int EnQueue(CircularQueue *Q , int data){
    if (IsFull(Q))
    {
        printf("队列已满，无法入队！\n");
        return 0;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MaxSize;  // 更新尾指针，循环处理
    return 1;
}

int DeQueue(CircularQueue *Q, int *data){
    if (IsEmpty(Q))
    {
         printf("队列为空，无法出队！\n");
        return 0;
    }
    *data = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;  // 更新头指针，循环处理
    return 1;
}

void PrintQueue(CircularQueue *Q){
     if (IsEmpty(Q)) {
        printf("队列为空！\n");
        return;
    }
    printf("队列中的元素：");
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
}


int main() {
    CircularQueue Q;
    InitQueue(&Q);  // 初始化队列

    // 入队操作
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);
    EnQueue(&Q, 40);
    PrintQueue(&Q);  // 输出：队列中的元素：10 20 30 40

    // 入队时满
    if (!EnQueue(&Q, 50)) {
        printf("入队失败：队列已满\n");
    }

    // 出队操作
    int dequeuedElement;
    DeQueue(&Q, &dequeuedElement);
    printf("出队元素：%d\n", dequeuedElement);  // 输出：出队元素：10
    PrintQueue(&Q);  // 输出：队列中的元素：20 30 40

    // 再次入队
    EnQueue(&Q, 50);
    PrintQueue(&Q);  // 输出：队列中的元素：20 30 40 50

    return 0;
}
