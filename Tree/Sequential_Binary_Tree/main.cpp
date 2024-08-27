//顺序存储二叉树
#include <stdio.h>

#define MAXSIZE 100

typedef struct {
    int value;
    bool isEmpty;
} TreeNode;

void initTree(TreeNode t[]) {
    for (int i = 0; i < MAXSIZE; i++) {
        t[i].isEmpty = true;
    }
}

int main() {
    TreeNode t[MAXSIZE];
    initTree(t);
    return 0;
}
