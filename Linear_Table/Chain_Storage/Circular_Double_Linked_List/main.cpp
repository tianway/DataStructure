//循环双链表（带头结点）
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L->next = L;
    L->prior = L;
    return true;
}

bool IsEmpty(DLinkList L) {
    return L->next == L;
}

bool IsTail(DLinkList L, DNode *p) {
    return p->next == L;
}

bool DestroyList(DLinkList &L) {
    while (L->next != NULL && L->next != L) {
        DNode *p = L->next;
        L->next = p->next;
        free(p);
    }
    free(L);
    L = NULL;
    return true;
}

int Length(DLinkList L) {
    int length = 0;
    DNode *p = L->next;
    while (p != NULL && p != L) {
        length++;
        p = p->next;
    }
    return length;
}

DNode *LocateElem(DLinkList L, int e) {
    DNode *p = L->next;
    while (p != L && p->data != e) {
        L = L->next;
    }
    if (p == L) {
        printf("未找到元素！\n");
        return NULL;
    }
    return p;
}

/**
 * 从循环双链表中获取第i个元素。
 *
 * @param L 链表的头指针。
 * @param i 想要获取的元素的索引。
 * @return 返回第i个元素的指针，如果索引不合法则返回NULL。
 *
 * 此函数首先检查索引i是否合法，即是否小于0。
 * 然后从链表的头开始遍历，直到找到第i个元素或者遍历回到链表头。
 * 如果遍历回到链表头仍未找到第i个元素，则说明索引超过链表长度，返回NULL。
 */
DNode *GetElem(DLinkList L, int i) {
    // 检查索引i是否小于0
    if (i < 0) {
        printf("查找位序不合法！\n");
        return NULL;
    }
    // 从链表头开始遍历
    DNode *p = L;
    int j = 0;
    // 遍历链表直到找到第i个元素或者遍历回到链表头
    while (p != NULL && j < i) {
        p = p->next;
        j++;
        // 如果遍历回到链表头仍未找到第i个元素，则说明索引超过链表长度
        if (p == L) {
            printf("查找位序超过链表长度，元素不存在！\n");
            return NULL;
        }
    }
    // 返回第i个元素的指针
    return p;
}

bool InsertNextNode(DNode *p, int e) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    DNode *s = (DNode *) malloc(sizeof(DNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}

bool InsertPriorNode(DNode *p, int e) {
    if (p == NULL || p->prior == NULL) {
        return false;
    }
    DNode *s = (DNode *) malloc(sizeof(DNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return true;
}

bool ListInsert(DLinkList &L, int i, int e) {
    if (i < 1) {
        printf("插入的位置不合法！\n");
        return false;
    }
    DNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

bool ListInsert_Prior(DLinkList &L, int i, int e) {
    if (i < 0) {
        printf("插入的位置不合法！\n");
        return false;
    }
    DNode *p = GetElem(L, i);
    return InsertPriorNode(p, e);
}

bool DeleteNextNode(DNode *p, int &e) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    DNode *q = p->next;
    e = q->data;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

bool DeletePriorNode(DNode *p, int &e) {
    if (p == NULL || p->prior == NULL) {
        return false;
    }
    DNode *q = p->prior;
    e = q->data;
    p->prior = q->prior;
    q->prior->next = p;
    free(q);
    return true;
}

bool ListDelete(DLinkList &L, int i, int &e) {
    if (i < 1) {
        printf("删除的位置不合法！\n");
        return false;
    }
    DNode *p = GetElem(L, i - 1);
    return DeleteNextNode(p, e);
}

bool ListDelete_Prior(DLinkList &L, int i, int &e) {
    if (i < 1) {
        printf("删除的位置不合法！\n");
        return false;
    }
    DNode *p = GetElem(L, i);
    return DeletePriorNode(p->next, e);
}

DLinkList ListCreate_HeadInsert(DLinkList &L) {
    int x;
    InitDLinkList(L);
    scanf("%d", &x);
    while (x != 0) {
        InsertNextNode(L, x);
        scanf("%d", &x);
    }
    return L;
}

DLinkList ListCreate_TailInsert(DLinkList &L) {
    int x;
    InitDLinkList(L);
    DNode *r = L;
    scanf("%d", &x);
    while (x != 0) {
        InsertNextNode(r, x);
        r = r->next;
        scanf("%d", &x);
    }
    return L;
}

void PrintList(DLinkList L) {
    DNode *p = L->next;
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DLinkList L;
    int e;

    // InitDLinkList(L);
    // ListInsert(L, 1, 1);
    // ListInsert(L, 2, 2);
    // ListInsert(L, 3, 3);
    // ListInsert_Prior(L, 2, 4);
    // PrintList(L);
    // ListDelete(L, 2, e);
    // ListDelete_Prior(L, 2, e);
    // PrintList(L);

    // ListCreate_HeadInsert(L);
    // PrintList(L);

    ListCreate_TailInsert(L);
    PrintList(L);

    DestroyList(L);
    return 0;
}
