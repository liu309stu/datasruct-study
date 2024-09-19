#include <stdio.h>
#include <stdlib.h>

// 定义单链表的节点结构
typedef struct Node {
    int data;            // 数据域
    struct Node *next;   // 指针域，指向下一个节点
} Node, *LinkList;

// 初始化链表，创建一个头节点
void InitList(LinkList *L) {
    *L = (Node *)malloc(sizeof(Node));  // 创建头节点
    if (*L == NULL) {
        exit(1);  // 分配失败，退出程序
    }
    (*L)->next = NULL;  // 头节点指向空，表示链表为空
}

// 插入元素
int ListInsert(LinkList L, int position, int element) {
    Node *p = L;  // p指向链表的头节点
    int i = 0;
    while (p != NULL && i < position - 1) {  // 找到插入位置的前驱节点
        p = p->next;
        i++;
    }
    if (p == NULL || i > position - 1) {  // 插入位置不合法
        return 0;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));  // 创建新节点
    if (newNode == NULL) {
        return 0;  // 分配失败
    }
    newNode->data = element;  // 将数据赋值给新节点
    newNode->next = p->next;  // 将新节点插入链表
    p->next = newNode;
    return 1;
}

// 删除元素
int ListDelete(LinkList L, int position) {
    Node *p = L;  // p指向链表的头节点
    int i = 0;
    while (p->next != NULL && i < position - 1) {  // 找到删除位置的前驱节点
        p = p->next;
        i++;
    }
    if (p->next == NULL || i > position - 1) {  // 删除位置不合法
        return 0;
    }
    Node *temp = p->next;  // 临时保存要删除的节点
    p->next = temp->next;  // 删除节点
    free(temp);  // 释放删除节点的内存
    return 1;
}

// 输出链表的所有元素
void PrintList(LinkList L) {
    Node *p = L->next;  // 跳过头节点
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList L;
    InitList(&L);

    // 插入元素
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    PrintList(L);  // 输出：10 20 30

    // 删除元素
    ListDelete(L, 2);
    PrintList(L);  // 输出：10 30

    return 0;
}
