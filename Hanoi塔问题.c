#include <stdio.h>

// 定义递归函数，用于解决Hanoi塔问题
void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        // 当只有一个盘子时，直接将其从source柱子移动到target柱子
        printf("Move disk %d from %c to %c\n", n, source, target);
    } else {
        // 递归调用：将前n-1个盘子从source柱子移动到auxiliary柱子，借助target柱子
        hanoi(n - 1, source, target, auxiliary);

        // 将第n个盘子从source柱子移动到target柱子
        printf("Move disk %d from %c to %c\n", n, source, target);

        // 递归调用：将n-1个盘子从auxiliary柱子移动到target柱子，借助source柱子
        hanoi(n - 1, auxiliary, source, target);
    }
}

int main() {
    int n;

    // 输入盘子的数量
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // 调用hanoi函数，将n个盘子从柱子A移动到柱子C，借助柱子B
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
