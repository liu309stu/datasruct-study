#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int top          ;
}SeqStack;

void InitStack(SeqStack *S){
    S -> top = -1; // 栈顶为负，表示为空栈
}

int IsEmpty(SeqStack *S){
    return S-> top == -1;
}

int IsFull(SeqStack *S){
    return S-> top == (MAXSIZE - 1);
}

int Push(SeqStack *S,int x){
    if(IsFull(S)){
        printf("The Stack is Full ,you can't push x in it\n");
        return 0;
    }
    S ->data[++(S->top)] = x;
    return 1;
}

int Pop(SeqStack *S,int *x){
    if(IsEmpty(S)){
        printf("The Stack is real empty, you can't pop item from it\n");
        return 0;
    }
    *x =  S ->data[(S->top)--];
    // 为什么不把top 位置的元素设空？
    return 1;
}

int Top(SeqStack *S, int *x){
    if (IsEmpty(S))
    {
        printf("The Stack is real empty, you can't get top item from it\n");
        return 0;
    }
    *x = S->data[S->top];
    return 1;
}

void PrintStack(SeqStack *S){
    if (IsEmpty(S))
    {
        printf("The Stack is real empty, you can't get top item from it\n");
        return ;
    }
    printf("The item in Stack from bottem to top is follow:");
    for (int i = 0; i <= S->top; i++)
    {
          printf("%d ", S->data[i]);
    }
    printf("\n");
}

int main(void)
{
    
     SeqStack S;
    InitStack(&S);  // 初始化栈

    // 入栈
    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);
    PrintStack(&S);  // 输出栈中的元素：10 20 30

    // 获取栈顶元素
    int topElement;
    Top(&S, &topElement);
    printf("栈顶元素是：%d\n", topElement);  // 输出：栈顶元素是：30

    // 出栈
    int popElement;
    Pop(&S, &popElement);
    printf("弹出的元素是：%d\n", popElement);  // 输出：弹出的元素是：30
    PrintStack(&S);  // 输出栈中的元素：10 20

    return 0;
}
