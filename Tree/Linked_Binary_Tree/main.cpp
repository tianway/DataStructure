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

struct LinkNode {
    BiTNode *data;
    struct LinkNode *next;
};

typedef struct LinkQueue {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, BiTNode *e) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

bool DeQueue(LinkQueue &Q, BiTNode *&e) {
    if (Q.front == Q.rear)
        return false;
    LinkNode *s = Q.front->next;
    e = s->data;
    Q.front->next = s->next;
    if (Q.rear == s)
        Q.rear = Q.front;
    free(s);
    return true;
}

void init_bi_tree(BiTree &t) {
    t = (BiTree) malloc(sizeof(BiTNode));
    t->data.value = 1;
    t->lchild = t->rchild = NULL;
}
BiTNode *q;
BiTNode *pre = NULL;
BiTNode *final = NULL;

void visit(BiTNode *p) {
    if (p == q)
        final = pre;
    else
        pre = p;
}

void preorder(BiTree t) {
    if (t != NULL) {
        visit(t);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(BiTree t) {
    if (t != NULL) {
        inorder(t->lchild);
        visit(t);
        inorder(t->rchild);
    }
}

void postorder(BiTree t) {
    if (t != NULL) {
        postorder(t->lchild);
        postorder(t->rchild);
        visit(t);
    }
}

int treeDepth(BiTree t) {
    if (t == NULL)
        return 0;
    else {
        int l = treeDepth(t->lchild);
        int r = treeDepth(t->rchild);
        return (l > r ? l : r) + 1;
    }
}

void levelorder(BiTree t) {
    LinkQueue Q;
    BiTree p;
    InitQueue(Q);
    EnQueue(Q, t);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
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
