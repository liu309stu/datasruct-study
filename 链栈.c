#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;               //数据域
    struct Node *next;      //指针域
}Node,*LinkedStack;

void InitStack(LinkedStack *S){
    *S = NULL;
}

int IsEmpty(LinkedStack *S){
    return *S == NULL;
}

int Push(LinkedStack *S, int data){
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    newnode ->data = data;
    newnode ->next = *S  ;
    *S = newnode;
    return 1;
}


int Pop(LinkedStack *S,int *x){
    if (IsEmpty(*S))
    {
        printf("栈为空，无法出栈！\n");
        return 0;
    }
    Node *temp = *S;
    *x   =  temp ->data;
    *S   =  temp ->next;
    free(temp);
    return 1;
}


// 获取栈顶元素（不弹出）
int Top(LinkedStack S, int *x) {
    if (IsEmpty(S)) {        // 判断栈是否为空
        printf("栈为空，无栈顶元素！\n");
        return 0;
    }
    *x = S->data;            // 获取栈顶元素
    return 1;
}

// 打印栈中的所有元素
void PrintStack(LinkedStack S) {
    if (IsEmpty(S)) {
        printf("栈为空！\n");
        return;
    }
    Node *p = S;             // 从栈顶开始遍历
    printf("栈中的元素：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkedStack S;
    InitStack(&S);  // 初始化栈

    // 入栈
    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);
    PrintStack(S);  // 输出：栈中的元素：30 20 10

    // 获取栈顶元素
    int topElement;
    Top(S, &topElement);
    printf("栈顶元素是：%d\n", topElement);  // 输出：栈顶元素是：30

    // 出栈
    int popElement;
    Pop(&S, &popElement);
    printf("弹出的元素是：%d\n", popElement);  // 输出：弹出的元素是：30
    PrintStack(S);  // 输出：栈中的元素：20 10

    return 0;
}
