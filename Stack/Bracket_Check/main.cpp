//栈的应用：括号匹配
#include<stdio.h>
#include<string.h>

#define MAXSIZE 10

typedef struct {
    char data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, char x) {
    if (S.top == MAXSIZE - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, char &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    return true;
}

bool BracketsCheck(char *str, int length) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else {
            if (StackEmpty(S)) {
                return false;
            }
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(') {
                return false;
            }
            if (str[i] == ']' && topElem != '[') {
                return false;
            }
            if (str[i] == '}' && topElem != '{') {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

int main() {
    char str[] = "{([])}";
    int length = strlen(str);
    if (BracketsCheck(str, length)) {
        printf("括号匹配\n");
    } else {
        printf("括号不匹配\n");
    }
    return 0;
}
