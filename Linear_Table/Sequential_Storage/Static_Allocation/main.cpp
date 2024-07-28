//顺序表（静态分配）
#include <stdio.h>
#define MAXSIZE 10

typedef struct SqList {
    int data[MAXSIZE];
    int length;
} Sqlist;

void InitList(SqList &L) {
    for (int i = 0; i < MAXSIZE; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool InsertList(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        printf("插入位序不合法，插入失败\n");
        return false;
    }
    if (L.length >= MAXSIZE) {
        printf("顺序表空间已满，插入失败\n");
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    printf("在位序为%d的位置插入值%d\n");
    return true;
}

bool DeleteList(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) {
        printf("删除位序不合法，删除失败\n");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("删除位序为%d的值%d\n", i, e);
    return true;
}

int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) {
        printf("位序不合法\n");
        return -1;
    }
    return L.data[i - 1];
}

int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //返回值对应位序
        }
    }
    printf("未找到元素%d\n", e);
    return -1;
}

int main() {
    SqList L;
    int e = -1;
    InitList(L);
    for (int i = 0; i < 5; i++) {
        InsertList(L, i + 1, i + 1);
    }
    PrintList(L);
    DeleteList(L, 3, e);
    PrintList(L);
    printf("位序为3的值为%d\n", GetElem(L, 3));
    printf("值为2的位序为%d\n", LocateElem(L, 2));
    return 0;
}
