#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node , *CircularLinkedList;

void InitCirList(CircularLinkedList *L){
    *L = (Node *)malloc(sizeof(Node));
    if(*L == NULL){
        // 内存分配失败
        exit(1);
    }
    (*L)->next = *L;  // 头节点的next指向自己，形成循环
};

int InsertList(CircularLinkedList L , int position , int data){
    int i = 0;
    Node *p = L;  // p指向头节点
    // 循环链表特殊判断条件，p->next != *L为链表终点判断。
    while (p->next != L && i < position -1)
    {
        p = p->next;
        i++;
    }
    if (i != position -1)
    {
        // 插入位置不合法
        return 0;
    }

    Node * newNode = (Node *)malloc(sizeof(Node)); 
    if (newNode ==NULL)
    {
        return 0;
    }
    newNode -> data = data ;
    newNode -> next = p->next;
    p->next = newNode;
    return 1;
};


int deleteList(CircularLinkedList L , int position){
    int i = 0;
    Node *p = L;  // p指向头节点
    // 循环链表特殊判断条件，p->next != *L为链表终点判断。
    while (p->next != L && i < position -1)
    {
        p = p->next;
        i++;
    }
    if (i != position -1)
    {
        return 0;
    }
    p -> next = p -> next -> next;
    return 1;
};

void PrintList(CircularLinkedList L){
    Node *p = L ->next;  // p指向头节点
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }while (p!=L);
    printf("\n");
}

int main(){
     CircularLinkedList L;
    InitCirList(&L);  // 初始化循环链表

    // 插入元素
    InsertList(L, 1, 10);
    InsertList(L, 2, 20);
    InsertList(L, 3, 30);
    PrintList(L);  // 输出：10 20 30

    // 删除元素
    deleteList(L, 2);
    PrintList(L);  // 输出：10 30

    return 0;
}
