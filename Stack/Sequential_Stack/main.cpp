//顺序栈
#include <stdio.h>

#define Maxsize 10

typedef struct {
    int data[Maxsize];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, int x) {
    if (S.top == Maxsize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, int &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

int main() {
    SqStack S;
    int x;
    InitStack(S);

    for (int i = 0; i < 10; i++) {
        Push(S, i);
    }
    GetTop(S, x);
    printf("%d\n", x);
    while (!StackEmpty(S)) {
        Pop(S, x);
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}
