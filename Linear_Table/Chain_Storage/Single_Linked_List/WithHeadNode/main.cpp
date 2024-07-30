//单链表（带头结点）
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

bool IsEmpty(LinkList L) {
    return L->next == NULL;
}

bool DestroyList(LinkList &L) {
    while (L->next != NULL) {
        LNode *p = L->next;
        L->next = p->next;
        free(p);
    }
    free(L);
    L = NULL;
    return true;
}

int length(LinkList L) {
    int len = 0;
    LNode *p = L->next;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

LNode *GetElem(LinkList L, int i) {
    if (i < 0) {
        printf("查找位序不合法！\n");
        return NULL;
    }
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool InsertNextNode(LNode *&p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *&p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = p->data;
    s->next = p->next;
    p->data = e;
    p->next = s;
    return true;
}

bool InsertList(LinkList &L, int i, int e) {
    if (i < 1) {
        printf("插入位置不合法！\n");
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

bool InsertList_Prior(LinkList &L, int i, int e) {
    if (i < 1) {
        printf("插入位置不合法！\n");
        return false;
    }
    LNode *p = GetElem(L, i);
    return InsertPriorNode(p, e);
}

bool DeleteNextNode(LNode *&p, int &e) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    LNode *s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

bool DeleteThisNode(LNode *&p, int &e) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    e = p->data;
    LNode *s = p->next;
    p->data = s->data;
    p->next = s->next;
    free(s);
    return true;
}

bool DeleteList(LinkList &L, int i, int &e) {
    if (i < 1) {
        printf("删除位置不合法！\n");
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    return DeleteNextNode(p, e);
}

bool DeleteList_Next(LinkList &L, int i, int &e) {
    if (i < 1) {
        printf("删除位置不合法！\n");
        return false;
    }
    LNode *p = GetElem(L, i);
    return DeleteThisNode(p, e);
}

void PrintList(LinkList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkList List_HeadInsert(LinkList &L) {
    InitList(L);
    int n;
    scanf("%d", &n);
    while (n != -1) {
        InsertNextNode(L, n);
        scanf("%d", &n);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    InitList(L);
    LNode *r = L;
    int n;
    scanf("%d", &n);
    while (n != -1) {
        InsertNextNode(r, n);
        r = r->next;
        scanf("%d", &n);
    }
    return L;
}

int main() {
    LinkList L;

    // int e;
    // InitList(L);
    // InsertList(L, 1, 1);
    // InsertList(L, 2, 2);
    // InsertList(L, 3, 3);
    // InsertList_Prior(L, 3, 4);
    // PrintList(L);
    // DeleteList(L, 3, e);
    // DeleteList_Next(L, 2, e);
    // PrintList(L);

    // List_HeadInsert(L);
    // PrintList(L);

    List_TailInsert(L);
    PrintList(L);

    return 0;
}
