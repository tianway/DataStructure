//串的KMP模式匹配算法
#include <stdio.h>

#define MAXLEN 100

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

int index(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
    return 0;
}

int main() {
    SString S, T;
    // 根据模式串T，生成next数组
    // 调用函数
    return 0;
}
