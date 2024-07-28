//˳�����̬���䣩
#include <stdio.h>
#include <stdlib.h>
#define InitSize 100

typedef struct Seqlist {
    int *data;
    int length;
    int MaxSize;
} Seqlist;

void InitList(Seqlist &L) {
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void PrintList(Seqlist L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool InsertList(Seqlist &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        printf("����λ�򲻺Ϸ�������ʧ��\n");
        return false;
    }
    if (L.length >= L.MaxSize) {
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

bool DeleteList(Seqlist &L, int i, int &e) {
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

int GetElem(Seqlist L, int i) {
    if (i < 1 || i > L.length) {
        printf("λ�򲻺Ϸ�\n");
        return -1;
    }
    return L.data[i - 1];
}

int LocateElem(Seqlist L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //����ֵ��Ӧλ��
        }
    }
    printf("δ�ҵ�Ԫ��%d\n", e);
    return -1;
}

void ExpandList(Seqlist &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    free(p);
    L.MaxSize += len;
    printf("���ݳɹ�\n");
}

void DestroyList(Seqlist &L) {
    free(L.data);
    L.length = 0;
    L.MaxSize = 0;
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
    printf("λ��Ϊ%d��ֵΪ%d\n", 3, GetElem(L, 3));
    printf("ֵΪ%d��Ԫ��λ��Ϊ%d\n", 3, LocateElem(L, 3));
    ExpandList(L, 10);
    DestroyList(L);
    return 0;
}
