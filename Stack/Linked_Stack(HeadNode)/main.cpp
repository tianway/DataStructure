//链栈（带头节点）
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LiStack;

void InitStack(LiStack *&S) {
    S = (LiStack *) malloc(sizeof(LiStack));
    S->next = NULL;
}

bool DestroyStack(LiStack *&S) {
    if (S == NULL)
        return false;
    LiStack *p = S->next;
    while (p != NULL) {
        S->next = p->next;
        free(p);
        p = S->next;
    }
    free(S);
    return true;
}

bool StackEmpty(LiStack *S) {
    return S->next == NULL;
}

bool Push(LiStack *&S, int x) {
    if (S == NULL)
        return false;
    LiStack *p = (LiStack *) malloc(sizeof(LiStack));
    if (p == NULL) {
        return false;
    }
    p->data = x;
    p->next = S->next;
    S->next = p;
    return true;
}

bool Pop(LiStack *&S, int &x) {
    if (StackEmpty(S))
        return false;
    LiStack *p = S->next;
    x = p->data;
    S->next = p->next;
    free(p);
    return true;
}

bool GetTop(LiStack *S, int &x) {
    if (StackEmpty(S))
        return false;
    x = S->next->data;
    return true;
}

int main() {
    LiStack *S;
    InitStack(S);

    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    int x;
    Pop(S, x);
    printf("%d\n", x);
    GetTop(S, x);
    printf("%d\n", x);
    DestroyStack(S);

    return 0;
}
