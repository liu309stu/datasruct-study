#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100  // 顺序表的最大长度
// 定义顺序表的数据结构
typedef struct {
    int data[MAXSIZE]; // 存储数据的数组
    int length;        // 顺序表当前的长度
} SqList;
// 初始化顺序表
void InitList(SqList *L) {
    L->length = 0;
}
int ListInsert(SqList *L, int position, int data) {
    if (position <1 || position > L->length + 1)
    {  
       // 插入位置不合法
       return 0 ; 
    }

    if (L->length >= MAXSIZE){
        // 顺序表已满
        return 0;
    }
    // 将插入位置及其后面的元素后移
    for (int i = L -> length; i >= position; i--)
    {
        L->data[i] = L->data[i - 1];        
    }
    // 插入
    L -> data[position - 1] = data;
    L -> length ++;
    return 1;
}
int ListDelete(SqList *L, int position) {
    if (position < 1 || position > L->length){
        return 0;
    }

    for (int i = position; i <= L->length - 1; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length --;
    return 1;
}
void PrintList(SqList *L) {
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\t");
}
int main() {
   SqList L;
   InitList(&L);
   ListInsert(&L, 1, 3);
   ListInsert(&L, 2, 2);
   ListInsert(&L, 3, 3);
   PrintList(&L);
   ListDelete(&L, 3);
   PrintList(&L);
   return 0;
}
