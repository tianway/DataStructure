//链式存储二叉树
#include <stdio.h>
#include <stdlib.h>

struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void init_bi_tree(BiTree &t) {
    t = (BiTree) malloc(sizeof(BiTNode));
    t->data.value = 1;
    t->lchild = t->rchild = NULL;
}

int main() {
    BiTree t = NULL;
    init_bi_tree(t);
    BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
    p->data.value = 2;
    p->lchild = p->rchild = NULL;
    t->lchild = p;
    return 0;
}
