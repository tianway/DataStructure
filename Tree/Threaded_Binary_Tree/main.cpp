//线索二叉树
#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType {
    char data;
} ElemType;

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *pre;

void visit(ThreadNode *q) {
    if (q->lchild == NULL) {
        q->ltag = 1;
        q->lchild = pre;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = q;
    }
    pre = q;
}

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void CreateInThread(ThreadTree &T) {
    pre = NULL;
    if (T != NULL) {
        InThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

void PreThread(ThreadTree &T) {
    if (T != NULL) {
        visit(T);
        if (T->ltag == 0)
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void CreatePreThread(ThreadTree &T) {
    pre = NULL;
    if (T != NULL) {
        PreThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

void PostThread(ThreadTree &T) {
    if (T != NULL) {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

void CreatePostThread(ThreadTree &T) {
    pre = NULL;
    if (T != NULL) {
        PostThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}

int main() {
    return 0;
}
