//链栈（无头结点）
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LiStack;

void InitStack(LiStack *&S) {
    S = NULL;
}

bool DestroyStack(LiStack *&S) {
    if (S == NULL)
        return false;
    LiStack *p = S;
    while (p != NULL) {
        S = S->next;
        free(p);
        p = S;
    }
    return true;
}

bool StackEmpty(LiStack *S) {
    return S == NULL;
}

bool Push(LiStack *&S, int e) {
    LiStack *p = (LiStack *) malloc(sizeof(LiStack));
    if (p == NULL)
        return false;
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

bool Pop(LiStack *&S, int &e) {
    if (S == NULL)
        return false;
    LiStack *p = S;
    e = p->data;
    S = p->next;
    free(p);
    return true;
}

bool GetTop(LiStack *S, int &e) {
    if (S == NULL)
        return false;
    e = S->data;
    return true;
}

int main() {
    LiStack *S;
    InitStack(S);

    for (int i = 0; i < 10; i++) {
        Push(S, i);
    }
    int e;
    if (GetTop(S, e)) {
        printf("%d\n", e);
    }
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%d ", e);
    }
    printf("\n");

    DestroyStack(S);

    return 0;
}
