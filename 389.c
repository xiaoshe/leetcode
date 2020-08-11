#include "util.h"

/*
// 方法1
char findTheDifference(char *s, char *t) {
    char m[26] = {0};
    while (*s != 0) {
        m[*s - 'a']++;
        s++;
    }
    while (*t != 0) {
        int p = *t - 'a';
        if (m[p] > 0) {
            m[p]--;
        } else {
            return *t;
        }
        t++;
    }
    return '0';
}
*/

/*
// 方法2
char findTheDifference(char *s, char *t) {
    int sum = 0;
    while (*s != 0) {
        sum += *t - 'a'; // 因为t多一个字符，这样sum最后是正数
        sum -= *s - 'a';
        s++, t++;
    }
    sum += *t - 'a';
    return sum + 'a';
}
*/

// 方法3:异或
// 异或抵消相同的值
char findTheDifference(char *s, char *t) {
    int x = 0;
    while (*s != 0) {
        x = x ^ (*s ^ *t);
        s++, t++;
    }
    return x ^ *t;
}

int main(int argc, char *argv[]) {
    char ret = findTheDifference(argv[1], argv[2]);
    printf("ret:%c\n", ret);
    return 0;
}
