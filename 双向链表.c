#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;                // 数据域
    struct Node *next;       // 指向下一个节点的指针
    struct Node *prev;       // 指向前一个节点的指针
}Node , *DoublyLinkedList;

void InitDoublyList(DoublyLinkedList* L){
    *L = (Node *)malloc(sizeof(Node));
    if (*L == NULL)
    {
        exit(1); // 内存分配失败
    }
    (*L) ->next = NULL;
    (*L) ->prev = NULL;
};

int InsertList(DoublyLinkedList L , int position , int data){
    int i = 0;
    Node *p = L ;
    while (p !=NULL && i < position -1)
    {
        p = p->next;
        i++;
    }
    if (p == NULL || i != position - 1)
    {
       return 0;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 0;
    }
    newNode ->data = data ;
    newNode ->next = p->next;
    newNode ->prev = p;

    if (p->next != NULL)
    {
       p->next->prev = newNode;
    }
    
    p->next = newNode;
    return 1;
};

int deleteList(DoublyLinkedList L , int position){
    int i = 0;
    Node *p = L;
    while (p->next != NULL && i < position - 1)
    {
       p = p -> next;
       i++;
    }
    if(p->next == NULL || i != position -1){
        return 0;
    }
    Node *temp = p->next;
    p ->next = temp -> next;
    if (temp->next != NULL)
    {
        temp->next->prev = p;
    }
    free(temp);
    
    return 1;
}


void PrintList(DoublyLinkedList L){
    Node *p = L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p ->next;
    }
    printf("\n");
};

void PrintBackList(DoublyLinkedList L){
    Node *p = L;  // p指向头节点
    while (p->next != NULL) {  // 找到最后一个节点
        p = p->next;
    }
    // 从最后一个节点向前遍历
    while (p != L) {  // 直到p回到头节点
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
};


int main(){
    DoublyLinkedList L;
    InitDoublyList(&L);  // 初始化双向链表

    // 插入元素
    InsertList(L, 1, 10);
    InsertList(L, 2, 20);
    InsertList(L, 3, 30);
    PrintList(L);  // 从头到尾输出：10 20 30

    // 从尾到头输出
    PrintBackList(L);  // 从尾到头输出：30 20 10

    // 删除元素
    deleteList(L, 2);
    PrintList(L);  // 从头到尾输出：10 30

    // 从尾到头输出
    PrintBackList(L);  // 从尾到头输出：30 10

    return 0;
}
