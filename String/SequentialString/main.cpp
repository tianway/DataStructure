//顺序串
#include <stdio.h>

#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

int StrLength(SString S) {
    return S.length;
}

bool ClearString(SString &S) {
    S.length = 0;
    return true;
}

bool SubString(SString &Sub, SString S, int pos, int len) {
    //子串范围越界
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

//比较操作。若S>T，返回值>0；S=T，返回值=0；S<T，返回值<0。
bool StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

//主串S中查找子串T的位置，若找到，返回值是子串T在主串S中的位置；否则返回值是0。
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) == 0) {
            return i;
        }
        i++;
    }
    return 0;
}

int main() {
    SString S, T;
    S.ch[1] = 'w';
    S.ch[2] = 'o';
    S.ch[3] = 'r';
    S.ch[4] = 'd';
    S.length = 4;
    T.ch[1] = 'o';
    T.ch[2] = 'r';
    T.length = 2;
    printf("%d", Index(S, T));
    return 0;
}
