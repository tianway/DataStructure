//静态链表
#include <stdio.h>

#define MAXSIZE 10

typedef struct Node {
    int data;
    int next;
} SLinkList[MAXSIZE];

void InitList(SLinkList L) {
    L->next = -1;
    for (int i = 1; i <= MAXSIZE - 1; ++i) {
        L[i].next = -2;
    }
}

Node *LocateElem(SLinkList L, int e) {
    if (L->next == -1) {
        printf("链表为空！");
        return NULL;
    }
    int cursor = L->next;
    while (cursor != -1 && L[cursor].data != e) {
        cursor = L[cursor].next;
    }
    if (cursor == -1) {
        printf("未找到元素！");
        return NULL;
    }
    return &L[cursor];
}

Node *GetElem(SLinkList L, int i) {
    if (i < 0 || i > MAXSIZE - 1) {
        printf("查找位序不合法！");
        return NULL;
    }
    int j = 0;
    int cursor = 0;
    while (cursor != -1 && j < i) {
        cursor = L[cursor].next;
        j++;
    }
    if (cursor == -1) {
        printf("查找位序超过链表长度！");
        return NULL;
    }
    return &L[cursor];
}

bool InsertList(SLinkList L, int i, int e) {
    if (i < 1 || i >= MAXSIZE - 1) {
        printf("插入位序不合法！");
        return false;
    }
    int cursor = 0;
    for (int j = 1; j <= MAXSIZE - 1; ++j) {
        if (L[j].next == -2) {
            cursor = j;
            break;
        };
    }
    if (cursor == 0) {
        printf("链表已满！");
        return false;
    }
    L[cursor].data = e;
    Node *p = GetElem(L, i - 1);
    if (p == NULL) {
        return false;
    }
    L[cursor].next = p->next;
    p->next = cursor;
    return true;
}

bool DeleteList(SLinkList L, int i) {
    if (i < 1 || i > MAXSIZE - 1) {
        printf("删除位序不合法！");
        return false;
    }
    Node *p = GetElem(L, i - 1);
    if (p == NULL) {
        return false;
    }
    int cursor = p->next;
    p->next = L[cursor].next;
    L[cursor].next = -2;
    return true;
}

void PrintList(SLinkList L) {
    int cursor = L->next;
    while (cursor != -1) {
        printf("%d ", L[cursor].data);
        cursor = L[cursor].next;
    }
    printf("\n");
}

int main() {
    SLinkList L;

    InitList(L);
    InsertList(L, 1, 1);
    InsertList(L, 2, 2);
    InsertList(L, 3, 3);
    PrintList(L);
    DeleteList(L, 2);
    PrintList(L);

    return 0;
}
