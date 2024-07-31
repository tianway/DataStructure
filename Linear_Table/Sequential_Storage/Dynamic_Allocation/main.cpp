//顺序表（动态分配）
#include <stdio.h>
#include <stdlib.h>

#define InitSize 100

typedef struct Seqlist {
    int *data;
    int length;
    int MaxSize;
} Seqlist;

bool InitList(Seqlist &L) {
    L.data = (int *) malloc(InitSize * sizeof(int));
    if (L.data == NULL) {
        return false;
    }
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}

void PrintList(Seqlist L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool InsertList(Seqlist &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        printf("插入位序不合法，插入失败\n");
        return false;
    }
    if (L.length >= L.MaxSize) {
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

bool DeleteList(Seqlist &L, int i, int &e) {
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

int GetElem(Seqlist L, int i) {
    if (i < 1 || i > L.length) {
        printf("位序不合法\n");
        return -1;
    }
    return L.data[i - 1];
}

int LocateElem(Seqlist L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //返回值对应位序
        }
    }
    printf("未找到元素%d\n", e);
    return -1;
}

bool ExpandList(Seqlist &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    if (L.data == NULL) {
        return false;
    }
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    free(p);
    L.MaxSize += len;
    return true;
}

bool DestroyList(Seqlist &L) {
    free(L.data);
    L.length = 0;
    L.MaxSize = 0;
    return true;
}

int main() {
    Seqlist L;
    InitList(L);
    for (int i = 0; i < 5; i++) {
        InsertList(L, i + 1, i + 1);
    };
    PrintList(L);
    int e;
    DeleteList(L, 3, e);
    PrintList(L);
    printf("位序为%d的值为%d\n", 3, GetElem(L, 3));
    printf("值为%d的元素位序为%d\n", 3, LocateElem(L, 3));
    ExpandList(L, 10);
    DestroyList(L);
    return 0;
}
