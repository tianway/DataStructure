//串的朴素模式匹配算法
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

int index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) return i - T.length;
    return 0;
}

int main() {
    SString S, T;
    S.ch[1] = 'a';
    S.ch[2] = 'b';
    S.ch[3] = 'c';
    T.ch[1] = 'b';
    S.length = 3;
    T.length = 1;
    int pos = index(S, T);
    printf("%d", pos);
    return 0;
}
