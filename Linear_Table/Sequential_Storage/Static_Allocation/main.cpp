//˳�����̬���䣩
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
        printf("����λ�򲻺Ϸ�������ʧ��\n");
        return false;
    }
    if (L.length >= MAXSIZE) {
        printf("˳���ռ�����������ʧ��\n");
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    printf("��λ��Ϊ%d��λ�ò���ֵ%d\n");
    return true;
}

bool DeleteList(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) {
        printf("ɾ��λ�򲻺Ϸ���ɾ��ʧ��\n");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("ɾ��λ��Ϊ%d��ֵ%d\n", i, e);
    return true;
}

int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) {
        printf("λ�򲻺Ϸ�\n");
        return -1;
    }
    return L.data[i - 1];
}

int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //����ֵ��Ӧλ��
        }
    }
    printf("δ�ҵ�Ԫ��%d\n", e);
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
    printf("λ��Ϊ3��ֵΪ%d\n", GetElem(L, 3));
    printf("ֵΪ2��λ��Ϊ%d\n", LocateElem(L, 2));
    return 0;
}
