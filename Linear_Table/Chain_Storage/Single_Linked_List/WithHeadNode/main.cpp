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

/**
 * 使用头插法创建一个单链表。
 *
 * 本函数首先初始化一个空链表，然后从用户输入读取一系列整数。
 * 每读取一个整数，就使用头插法将其插入链表中。
 * 用户输入-1来表示输入结束。
 *
 * @param L 链表的头结点指针的引用，用于在函数内部修改链表。
 * @return 返回创建完成的链表的头结点指针。
 */
LinkList List_HeadInsert(LinkList &L) {
    // 初始化一个空链表
    InitList(L);

    // 用于存储用户输入的整数
    int n;

    // 读取第一个用户输入的整数
    scanf("%d", &n);

    // 循环直到用户输入-1
    while (n != -1) {
        // 使用头插法将读取的整数插入链表中
        InsertNextNode(L, n);

        // 读取下一个用户输入的整数
        scanf("%d", &n);
    }

    // 返回创建完成的链表
    return L;
}


/**
 * 使用尾插法创建链表
 *
 * @param L 传入的链表头指针引用
 * @return 返回创建完成的链表头指针
 *
 * 此函数首先初始化链表，然后通过尾插法根据用户输入的数据创建链表
 * 用户输入-1作为结束标志，表示停止输入
 */
LinkList List_TailInsert(LinkList &L) {
    // 初始化链表
    InitList(L);
    // 创建一个指针r，初始时指向链表的头节点
    LNode *r = L;
    // n用于临时存储用户输入的数据
    int n;
    // 读取用户输入的第一个数据
    scanf("%d", &n);
    // 当用户输入的数据不是结束标志(-1)时，继续创建节点并插入到链表中
    while (n != -1) {
        // 在指针r所指节点的后面插入一个新节点，新节点的数据域为n
        InsertNextNode(r, n);
        // 将指针r移动到新插入的节点上，为下一次插入做准备
        r = r->next;
        // 读取下一个用户输入的数据
        scanf("%d", &n);
    }
    // 返回创建完成的链表头指针
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
