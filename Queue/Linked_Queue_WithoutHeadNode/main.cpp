//链式队列（不带头结点）
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
    int length;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = NULL;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == NULL;
}

bool EnQueue(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == NULL) {
        return false;
    }
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL) {
        Q.front = Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }
    return true;
}

bool DeQueue(LinkQueue &Q, int &x) {
    if (Q.front == NULL) {
        return false;
    }
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if (Q.rear == p) {
        Q.rear = NULL;
    }
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);

    return 0;
}
